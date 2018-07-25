package Sort;

import edu.princeton.cs.algs4.In;

/**
 * Created by zengq on 2015/9/21.
 */
public class Select extends SortModule
{
   public static void sort(Comparable[] a)
   {
      int N = a.length;
      for (int i = 0; i < N; i++) {
         int min = i;
         for (int j = i+1; j < N; j++) {
            if (less(a[j],a[min])) min = j;
         }
//         System.out.println("exch:"+i+" "+min);
         exch(a, i, min);
      }
   }

   public static void main(String[] args)
   {
//      String[] a = In.readStrings();
      String[] a = test(10);

      sort(a);
      assert isSorted(a);
      show(a);
   }
}
