package Sort;

/**
 * Created by zengq on 2015/9/21.
 */
public class Shell extends SortModule
{
    public static void sort(Comparable[] a)
    {
        int N = a.length;
        int h = 1;
        while (h < N/3) h = 3*h + 1; //1,4,13,40,121,364
        while (h >= 1)
        {   //��a[i]���뵽a[i-h],a[i-2*h],a[i-3*h]...֮��
            for (int i = h; i < N; i++) {
                for (int j = i; j >=h && less(a[j], a[j-h]) ; j-=h) {
                    exch(a,j,j-h);
                }
            }
            h = h/3;
        }
    }

    public static void main(String[] args) {
        String[] a = test(100);
        sort(a);
        assert isSorted(a);
        show(a);
    }
}
