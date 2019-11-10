for((i=0;;i++)) do
    echo $i
    ./gen $i > int
    diff -w <(./e < int) <(./brute < int) || break
done