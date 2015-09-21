package Sort;

import edu.princeton.cs.algs4.In;

/**
 * Created by zengq on 2015/9/21.
 */
public class SortModule {
    public static void sort(Comparable[] a)
    {   }

    protected static boolean less(Comparable v,Comparable w)
    { return v.compareTo(w) < 0; }

    protected static void exch(Comparable[] a, int i, int j)
    { Comparable t = a[i]; a[i] = a[j]; a[j] = t;}

    protected static void show(Comparable[] a)
    {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public static boolean isSorted(Comparable[] a)
    {
        for (int i = 0; i < a.length; i++) {
            if(less(a[i], a[i-1])) return false;
        }
        return true;
    }

    public static String[] test(int N)
    {
        String[] a = new String[N];
        for (int i = 0; i < N; i++) {
            a[i] = Integer.toString((int)(Math.random()*100));
            System.out.print(a[i]+" ");
        }
        System.out.println();

        return a;
    }

}
