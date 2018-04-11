(M, S, T) = (39, 200, 4)


def escape(M, S, T):
    flash_dis = 0
    distance = 0
    run_speed = 17

    for time in range(1, T+1):
        distance += run_speed
        if(M >= 10):
            M -= 10
            flash_dis += 60
        else:
            M += 4

        distance = (distance if (distance > flash_dis) else flash_dis)

        if(distance >= S):
            print('yes', '\n', time, M)
            return

    print('no', '\n', distance, M)


escape(M, S, T)
