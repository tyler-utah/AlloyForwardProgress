#!/bin/bash

numthread=$1
progressmodel=$2 # optional, defaults to LOBE

if test -z $progressmodel
then
   progressmodel="LOBE"
fi

module=mcc${numthread}${progressmodel}

echo "Generate ${module}.lnt"

(
  echo "module ${module} is"
  cat header.lnt
  echo "ALL_DONE -> sharedMemory[STEP, TERMINATE, ALL_DONE](${numthread})"
  echo "|| ALL_DONE -> ${progressmodel}[STEP, TERMINATE, ALL_DONE]"
  echo "|| par"
  ./create.py ${numthread}
  echo "  end par"
  echo "end par"
  echo "end process"
  echo "end module"
) > ${module}.lnt

set -x
set -e

#### Uncomment the follwoing to generate the BCGs
#lnt.open ${module}.lnt generator ${module}.bcg
#bcg_min ${module}.bcg ${module}.min.bcg
#bcg_info ${module}.bcg
#bcg_info ${module}.min.bcg
#bcg_draw -ps ${module}.min.bcg

#### The MCC steps
lnt.open ${module}.lnt -
caesar.adt ${module}.lotos
caesar -prenupn ${module}.lotos
mv ${module}.nupn ${module}.pre.nupn
caesar -nupn -simulator ${module}.lotos
mv ${module}.nupn ${module}.post.nupn
time caesar.bdd -mcc ${module}.pre.nupn
time caesar.bdd -mcc ${module}.post.nupn
