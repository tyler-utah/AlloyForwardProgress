// TODO next:
// Totally order threads
// Minimality somehow?

fun dom[r:univ->univ] : univ { r.univ }
fun ran[r:univ->univ] : univ { univ.r }

// Values (including zero)
sig V {}
one sig ZERO extends V {}
one sig ONE extends V {}

// Don't delete please! You can get weird values without
fact {
  V = ZERO + ONE
}

// Global locations
sig X {}

// Global memory maps global locations to values
sig G_memory {
   mem : X -> one V
}

// Threads
sig Thread {
   t_order : lone Thread
} 

// A local state maps the next instruction of a thread
// Previously used to hold registers
sig L_state {
  next_ins : lone Instruction
}

// The state of the whole system comprises a global memory and one local state per thread
sig S {
   G_state: one G_memory,
   T_state: Thread -> one L_state
}

// Instructions
sig Instruction {
   po : lone Instruction, // immediate successor in program order
   thd : one Thread // each instruction belongs to one thread
}

// Need to define that the first instruction in every thread the first one in po
pred first_instruction_check[t:Thread, i:Instruction] {
  i.thd = t
  i not in ran[po]
}

fun first_instruction[t:Thread]: lone Instruction {
  {i : Instruction | first_instruction_check[t,i]}
}

// Initial state
one sig START extends S {
}{
  G_state.mem[X] = ZERO // all memory locations are zero
  all t : Thread | T_state[t].next_ins = first_instruction[t]  // Every thread starts at its first instruction
}

// Final state(s)
sig END extends S {}

// Actions
sig A {
  pre : one S, // state before this action
  post : one S, // state after this action
  ins : one Instruction, // the instruction being executed
}

// Atomic Exch. Branch.
// This instruction combines an atomic exchange and branch.
// Combining instructions like this reduces the state space that
// Alloy needs to explore.
sig ATOMIC_EXCH_BRANCH extends Instruction {
   check_loc : one X,
   exch_val : lone V,
   check_val : one V,
   branch_target: lone Instruction
} {
  some branch_target implies (branch_target.@thd = thd)
}

// -------
// Instruction graveyard
// -------

// Store instruction
/*sig STORE extends Instruction {
  store_loc : one X, // location to store into
  store_val : one V // value to store
}*/

// Load instruction
/*sig LOAD extends Instruction {
  load_loc : one X, // location to load from
  load_reg : one R // register to load into
}{ 
  load_reg in thd.owns // the register being loaded into must be owned by this thread
}*/

// Branch-if-equal-to-zero instruction
/*sig BRANCH_EQUAL_ZERO extends Instruction {
  branch_reg : one R, // if the value in this register is zero ...
  branch_target: one Instruction // ...then branch to this instruction
}{
  branch_reg in thd.owns // the register being queried must be owned by this thread
  branch_target.@thd = thd // the branch target must be an instruction in this thread
}*/



fact { 
  // there are no other kinds of instruction
  Instruction in ATOMIC_EXCH_BRANCH 
}

fact po_facts {
  // instructions are in the same thread iff they are po-related
  all i1,i2 : Instruction | i1.thd = i2.thd iff i1 in i2.*po or i2 in i1.*po

  // po is acyclic
  no (iden & ^po)
}

fact t_order_facts {
  // instructions are in the same thread iff they are po-related
  all t1,t2 : Thread | t1 in t2.*t_order or t2 in t1.*t_order

  // po is acyclic
  no (iden & ^t_order)
}



// Helper function: reverse of pre
fun pre_rev : S -> A {
  ~pre
}

// Helper function: connecting states through actions
fun to : S -> S {
  pre_rev . post     // <--pre-- . --post-->
}

fun next : A -> A {
  post . pre_rev // --post--> . <--pre--
}

fun next_in_thd : A -> A {
  next & (ins.thd.~thd.~ins)
}

fun enabled_threads[s:S] : set Thread {
  pre_rev[s].ins.thd
}

fact wellformed_LTS {

  // All states are reachable from START
  S in START.*to
   
  // No action uses an END state as a pre-state
  no END.pre_rev 

  // At least one END state is always reachable
  S in *to.END 

  // No next_ins in local states from end states
  all l : L_state | l in END.T_state[univ] implies no l.next_ins

  // Each thread has at most one action out of a state
  all s : S | all disj a1,a2 : pre_rev[s] | a1.ins.thd != a2.ins.thd

  // Any thread enabled at a state reachable from s must also be enabled at s 
  all s : S | enabled_threads[s.*to] in enabled_threads[s]
}

// Instruction semantics:

fact state_change_of_atomic_exch_branch {

  all a : ATOMIC_EXCH_BRANCH.~ins |
    let x = a.ins.check_loc |
    let v = a.ins.exch_val |
    let c = a.ins.check_val |
    let t = a.ins.thd
  {
     // Location x gets new value in global state
    some v implies (a.post.G_state.mem[x] = v)
    no v implies  (a.post.G_state.mem[x] = a.pre.G_state.mem[x] )

    // Other locations in global memory keep their old values
    all x' : dom[a.post.G_state.mem] | 
      x' != x implies a.post.G_state.mem[x'] = a.pre.G_state.mem[x']

    //a.pre.T_state[t].regs = a.post.T_state[t].regs

    a.pre.G_state.mem[x] = c implies a.post.T_state[t].next_ins = a.ins.branch_target
    a.pre.G_state.mem[x] != c implies a.post.T_state[t].next_ins = a.ins.po

    all t' : Thread |
       t' != t implies a.post.T_state[t'] = a.pre.T_state[t']

  }
  
}

// ---
// Instruction Semantics Graveyard
// ---
// State change associated with load action
/*fact state_change_of_load {
  all a : LOAD.~ins |
  let x = a.ins.load_loc | // x is the location being loaded from
  let r = a.ins.load_reg | // r is the register being loaded into
  let t = a.ins.thd // t is the current thread
  {
    // Register r gets new value
    a.post.T_state[t].regs[r] = a.pre.G_state.mem[x]

    // Registers other than r keep their old values
    all r' : dom[a.post.T_state[t].regs] | 
      r' != r implies a.pre.T_state[t].regs[r'] = a.post.T_state[t].regs[r']

    // Global state stays the same
    a.post.G_state = a.pre.G_state
    
    a.post.T_state[t].next_ins = a.ins.po

   all t' : Thread |
     t' != t implies a.post.T_state[t'] = a.pre.T_state[t']
  }
}

// State change associated with branch action
fact state_change_of_branch {
  all a : BRANCH_EQUAL_ZERO.~ins |
  let t = a.ins.thd  |// t is the current thread
  let r = a.ins.branch_reg
  {
    // Global state stays the same
    a.post.G_state = a.pre.G_state
    a.pre.T_state[t].regs = a.post.T_state[t].regs
    
    a.pre.T_state[t].regs[r] != ZERO implies a.post.T_state[t].next_ins = a.ins.po
    a.pre.T_state[t].regs[r] = ZERO implies a.post.T_state[t].next_ins = a.ins.branch_target
    //a.post.T_state[t].next_ins = a.ins.po

    all t' : Thread |
       t' != t implies a.post.T_state[t'] = a.pre.T_state[t']
  }                     
}

// State change associated with store action
fact state_change_of_store {
  all a : STORE.~ins |
  let x = a.ins.store_loc | // x is the location being stored into
  let v = a.ins.store_val | // v is the value being stored
  let t = a.ins.thd // t is the current thread
  {
     
    // Location x gets new value in global state
    a.post.G_state.mem[x] = v 

    // Other locations in global memory keep their old values
    all x' : dom[a.post.G_state.mem] | 
      x' != x implies a.post.G_state.mem[x'] = a.pre.G_state.mem[x']
    

    // Registers other than r keep their old values
    //a.pre.T_state[t].regs = a.post.T_state[t].regs
    a.post.T_state[t].next_ins = a.ins.po

    // Other threads' local states are unchanged
    all t' : Thread | 
        t' != t implies (a.post.T_state[t'] = a.pre.T_state[t'])  
  }
}

*/

fact actions_respect_po {
  all s : S, t : Thread | some s.T_state[t].next_ins implies (some a : A | a in s.pre_rev and a.ins = s.T_state[t].next_ins)
  all s : S, t : Thread | no s.T_state[t].next_ins implies (no a : A | a in s.pre_rev and a.ins.thd = t)
}

fact no_surplus_L_states {
  L_state in S.T_state[Thread]
}

fact no_surplus_G_memories {
  G_memory in S.G_state
}

fact no_surplus_Threads {
  all t : Thread | some a : A | a.ins.thd = t
}

fact no_surplus_Locations {
  all x : X | some i : Instruction | i.check_loc = x
}

fun ao : A->A {
   ^(post.pre_rev)
}

// You can run this with your "interesting" predicate, but it can take a decent amount longer, but gives you minimal states
pred minimal_states {
  // Local states that have the same fields are the same
  all l1,l2 : L_state | (l1.next_ins = l2.next_ins) implies l1=l2
  
  // Global memory that have the same fields are the same
   all g1, g2 : G_memory | g1.mem = g2.mem implies g1 = g2

  // States that have the same fields are the same
  all s1,s2 : S | (s1.G_state = s2.G_state and (all t : Thread | s1.T_state[t] = s2.T_state[t])) implies s1 = s2
}

// With our single instructions, sometimes the atomic exchange branch is used as a store
// i.e. where po and branch target are the same. This is an effort to catch those cases and
// constrain the comparisons in those cases so that Alloy does not generate redundant
// tests based on inconsequential comparisons.
pred constrain_comparisons {
  all a : ATOMIC_EXCH_BRANCH | a.po = a.branch_target implies (a.check_val = ZERO and some a.exch_val)
}

// Stores are instructions where po = branch_target
// here we're saying that a store needs to access a memory location 
// touched by at least one load from another thread
pred constrain_stores {
 all i : ATOMIC_EXCH_BRANCH | some i.exch_val implies 
                                             ((some i' : ATOMIC_EXCH_BRANCH | 
                                                       i'.thd != i.thd and 
                                                       i'.po != i'.branch_target and // i' is not a store
                                                       i.check_loc = i'.check_loc) 
                                                       and
                                               (some a: A | a.ins = i and a.pre.G_state.mem[i.check_loc] != i.exch_val))

 // Also branches need to have some action from another thread 
 // touch the memory location
 all i : ATOMIC_EXCH_BRANCH | i.po != i.branch_target implies 
                                             (some i' : ATOMIC_EXCH_BRANCH | 
                                                       i'.thd != i.thd and 
                                                       i.check_loc = i'.check_loc)
}

// If an instruction is not a store (a.po = a.branch_target), then the execution should
// have both both po and the branch taken
pred constrain_branches {
  all i : ATOMIC_EXCH_BRANCH | i.po != i.branch_target implies (
            (some a:A | a.ins = i and a.pre.G_state.mem[i.check_loc] = i.check_val ) and (some a:A | a.ins = i and a.pre.G_state.mem[i.check_loc] != i.check_val))
}





pred minimal_programs {
   constrain_comparisons and constrain_branches and constrain_stores
}

// it needs to do a store followed by a load for this one.
pred interesting {
 // Something is interesting if there is a loop in action order. This must be blocking action under our semantics (a local loop would change the state space and thus be a different action 
 some a : A | a->a in ao
}

pred to_run {
   interesting and minimal_states and minimal_programs
}

// This is pretty small but it will show a producer/consumer example
run to_run for 2 V,  exactly 2 Thread,  7 S,  8 A, 5 L_state, 7 G_memory, 1 X,  exactly 3 Instruction
//run to_run for 2 V,   3 Thread,  7 S,  8 A, 5 L_state, 4 G_memory, 2 X,  4 Instruction
