#! /usr/bin/python
# coding: utf-8
from copy import copy

with open('./escape.in', 'r') as params:
    params = params.read().split(' ', 2)
    M = int(params[0])  # magic value
    S = int(params[1])  # distance
    T = int(params[2])  # time
    S_copy = copy(S)
    T_copy = copy(T)


class EscapeType(object):
    RUN = 'run'
    FLASH = 'flash'


class EscapeSpeed(object):
    RUN = 17
    FLASH = 60


class Flash(object):
    CONSUME = 10
    RECOVER = 4


def get_flash_CD(magv):
    if magv // Flash.CONSUME != 0:
        return 0

    return 1 + get_flash_CD(magv + Flash.RECOVER)


def get_run_distance(t):
    return t * EscapeSpeed.RUN


def one_step(es_type, es_speed):
    return {'%s' % es_type: es_speed}


def one_step_helper(magv, distance, time):
    if magv // Flash.CONSUME != 0:
        return one_step(EscapeType.FLASH, EscapeSpeed.FLASH)

    cd = get_flash_CD(magv)
    if (cd < time):
        run_distance = get_run_distance(cd + 1)
        flash_distance = EscapeSpeed.FLASH
        if (run_distance > flash_distance):
            return one_step(EscapeType.RUN, EscapeSpeed.RUN)

        return one_step(EscapeType.FLASH, EscapeSpeed.FLASH)

    return one_step(EscapeType.RUN, EscapeSpeed.RUN)

status = None
all_steps = []

while T > 0 and S > 0:
    all_steps.append(one_step_helper(M, S, T))
    T -= 1
    if EscapeType.FLASH in all_steps[-1]:
        if M < Flash.CONSUME:
            cd = get_flash_CD(M)
            T -= cd
            M += Flash.RECOVER * cd

        M -= Flash.CONSUME
        S -= EscapeSpeed.FLASH
    else:
        S -= EscapeSpeed.RUN


if S <= 0:
    status = True
    print(status, T_copy - T)
    with open('./escape.out', 'w') as output:
        output.write(str(status) + '\n')
        output.write(str(T_copy - T))
else:
    status = False
    print(status, S_copy - S)
    with open('./escape.out', 'w') as output:
        output.write(str(status) + '\n')
        output.write(str(S_copy - S))
