package Sort;

/**
 * Created by zengq on 2015/9/21.
 */
public class Insert extends SortModule
{
    public static void sort(Comparable[] a)
    {
        int N = a.length;
        for (int i = 0; i < N; i++) {
            for (int j = i; j > 0 && less(a[j], a[j-1]); j--) {
                exch(a,j,j-1);
            }
        }
    }

    public static void main(String[] args)
    {
        String[] a = test(10000);
        sort(a);
        assert isSorted(a);
        show(a);
    }
}
