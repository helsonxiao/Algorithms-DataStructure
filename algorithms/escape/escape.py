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


def get_flash_CD(magv, CD=0):
    if magv // FLASH_CONSUME != 0:
        return CD

    return get_flash_CD(magv + FLASH_RECOVER, CD + 1)


def one_step_helper(time, CD):
    if CD == 0:
        return 'flash'

    if (CD < time):
        run_distance = (CD + 1) * RUN_SPEED
        flash_distance = FLASH_SPEED
        if (run_distance > flash_distance):
            return 'run'

        return 'flash'

    return 'run'


RUN_SPEED = 17
FLASH_SPEED = 60
FLASH_CONSUME = 10
FLASH_RECOVER = 4
status = None

while T > 0 and S > 0:
    T -= 1
    CD = get_flash_CD(M)
    if one_step_helper(T, CD) is 'flash':
        if M < FLASH_CONSUME:
            T -= CD
            M += FLASH_RECOVER * CD

        M -= FLASH_CONSUME
        S -= FLASH_SPEED
    else:
        S -= RUN_SPEED


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
