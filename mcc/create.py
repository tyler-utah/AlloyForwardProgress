#!/usr/bin/env python3

import sys

numtheads=int(sys.argv[1])

s = ''

for tid in range(numtheads):
    if tid > 0:
        s += '||  '
    else:
        s += '    '
    s += 'interpreter[STEP, TERMINATE](' + str(tid) + ', {\n'
    # set own memory value
    s += '      AXB(MemLoc(' + str(tid) + '), 0, 2, true, 1)'
    instr = 2
    t = tid
    while t > 0:
        t -= 1
        instr += 2
        s += ',\n      '
        s += 'AXB(MemLoc(' + str(t) + '), 1, ' + str(instr) + ', false, 0)'
        s += ',\n      '
        s += 'AXB(MemLoc(' + str(t) + '), 0, ' + str(instr) + ', true, 1)'
    s += '\n    })\n'

print(s)
