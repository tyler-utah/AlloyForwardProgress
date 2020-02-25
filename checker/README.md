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
