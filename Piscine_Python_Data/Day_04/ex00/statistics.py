def ft_statistics(*args: any, **kwargs: any) -> None:

    for i in kwargs:
        if kwargs[i] == 'mean':
            try:
                assert len(args), "ERROR"
                for j in args:
                    assert isinstance(j, (int, float)), "ERROR"
                print('mean :', round(sum(args) / len(args), 1))
            except AssertionError as m:
                print(m)

        if kwargs[i] == 'median':
            try:
                assert len(args), "ERROR"
                for j in args:
                    assert isinstance(j, (int, float)), "ERROR"
                n = len(args)
                sorted_lst = sorted(list(args))
                if n % 2 == 0:
                    mid_right = sorted_lst[n // 2]
                    mid_left = sorted_lst[n // 2 - 1]
                    print('median:', mid_left + mid_right / 2)
                else:
                    print('median :', sorted_lst[n // 2])
            except AssertionError as m:
                print(m)

        if kwargs[i] == 'quartile':
            try:
                assert len(args), "ERROR"
                for j in args:
                    assert isinstance(j, (int, float)), "ERROR"
                sorted_lst = sorted(list(args))
                n = len(sorted_lst)

                q1_index = int(n * 0.25)
                q1 = sorted_lst[q1_index]

                q3_index = int(n * 0.75)
                q3 = sorted_lst[q3_index]

                print("quartile :", [float(q1), float(q3)])
            except AssertionError as m:
                print(m)

        if kwargs[i] == 'std':
            try:
                assert len(args), "ERROR"
                for j in args:
                    assert isinstance(j, (int, float)), "ERROR"
                n = len(args)
                mean = float(sum(args) / len(args))
                variance = sum((x - mean) ** 2 for x in args) / n
                std_dev = variance ** 0.5
                print("std :", std_dev)
            except AssertionError as m:
                print(m)

        if kwargs[i] == 'var':
            try:
                assert len(args), "ERROR"
                for j in args:
                    assert isinstance(j, (int, float)), "ERROR"
                n = len(args)
                mean = float(sum(args) / len(args))
                variance = sum((x - mean) ** 2 for x in args) / n
                print('var :', variance)
            except AssertionError as m:
                print(m)
