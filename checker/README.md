# GPU forward progress: formal verification of asbence of deadlocks

This is a specification of GPU programs doing inter-workgroup synchronizations,
under semi-fair schedulers.

It relies on [CADP](http://cadp.inria.fr/) tools.

To generate the LTS of e.g. prod_cons_obe:

```
# Generate the state space into a BCG (i.e. explicit LTS) file:
lnt.open prod_cons_obe.lnt generator prod_cons_obe.bcg

# See the graph:
bcg_edit prod_cons_obe.bcg

# You sometimes get better graph drawings using graphviz dot format:
bcg_io prod_cons_obe.bcg -graphviz prod_cons_obe.dot
xdot prod_cons_obe.dot
```

Verification can be scripted via SVL scripts, for instance you can run:

```
svl prod_cons.svl
```

## Some definitions

[CADP](http://cadp.inria.fr/) is a verification toolbox, and the following are
tools and languages related to it:

- LNT (Lotos NT) is a specification language, it is defined by the LNT-to-LOTOS
  translator reference manual, first published in 2005, but regularly updated:
  http://cadp.inria.fr/publications/Champelovier-Clerc-Garavel-et-al-10.html

- LTS means Labelled Transition System, we use this to represent the state-space
  of a model. States (vertices) have no information except a state number, only
  the label of transitions (edges) contains information. See wikipedia:
  https://en.wikipedia.org/wiki/Transition_system

- BCG is Binary Coded Graph, it is a binary format to store LTS.

- MCL is the Model Checking Language, a value-passing modal mu-calculus temporal
  logic used to express properties to be verified on models. MCL is the
  language, the CADP tool that process it is "evaluator". Here we use MCL
  version 4 (associated with evaluator4), as defined by its manual page:
  http://cadp.inria.fr/man/mcl4.html

- SVL (Script Verification Language) is a scripting language to use CADP
  tools. An SVL script expresses a verification scenario in a more readable and
  convenient way that a series of calls to CADP tools. SVL scripts can embed
  verification properties which are written in MCL. The SVL language is defined
  in http://cadp.inria.fr/man/svl-lang.html
