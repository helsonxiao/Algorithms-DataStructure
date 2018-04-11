#! /usr/bin/python
from copy import copy

with open('./escape.in', 'r') as params:
    params = params.read().split(' ', 2)
    M = int(params[0])  # magic value
    S = int(params[1])  # distance
    T = int(params[2])  # time
    S_copy = copy(S)
    T_copy = copy(T)

RUN_SPEED = 17
FLASH_SPEED = 60
FLASH_CONSUME = 10
FLASH_RECOVER = 4

times = []
times.append(0)
for t in range(1, T + 1):
    if (M >= FLASH_CONSUME):
        times.append(times[t-1] + FLASH_SPEED)
        M -= FLASH_CONSUME
    else:
        times.append(times[t-1])
        M += FLASH_RECOVER

status = None
end_time = None
for t in range(1, T + 1):
    t_run = times[t-1] + RUN_SPEED
    t_flash = times[t]
    if t_run > t_flash:
        times[t] = t_run

    if times[t] >= S:
        status = 'Yes'
        end_time = t
        break
    else:
        status = 'No'

if status == 'Yes':
    print(status, end_time)
    with open('./escape.out', 'w') as output:
        output.write(status + '\n')
        output.write(str(end_time))
else:
    print(status, times[T])
    with open('./escape.out', 'w') as output:
        output.write(status + '\n')
        output.write(str(times[T]))
