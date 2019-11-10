for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > input2.in
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./A < input2.in) <(./exp < input2.in) || break
done
