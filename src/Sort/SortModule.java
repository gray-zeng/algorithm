package Sort;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;

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

    public static void View(Comparable[] a)
    {
        int N = a.length;
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
            double x  = 1.0*i/N;
            double y  = Integer.parseInt((String)a[i])/200.0;
            double rw = 0.5/N;
            double rh = Integer.parseInt((String)a[i])/200.0;
            StdDraw.filledRectangle(x, y, rw, rh);
        }
        StdDraw.show(300);
        StdDraw.clear();
    }

    public static void View(Comparable[] a,int left,int right)
    {
        int N = a.length;
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
            double x  = 1.0*i/N;
            double y  = Integer.parseInt((String)a[i])/200.0;
            double rw = 0.5/N;
            double rh = Integer.parseInt((String)a[i])/200.0;
            if (i == left || i == right)
                StdDraw.setPenColor(255,0,0);
            StdDraw.filledRectangle(x,y,rw,rh);
            StdDraw.setPenColor(0,0,0);
        }
        StdDraw.show(300);
        StdDraw.clear();
    }
}
