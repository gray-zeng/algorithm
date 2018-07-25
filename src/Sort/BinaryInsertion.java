package Sort;

/**
 * Created by zengq on 2015/9/24.
 */
public class BinaryInsertion extends SortModule {
    // 折半查找 将一个记录插入到已排序好的有序序列中
    // 用二分查找来找到新纪录在有序序列中的位置
    public static void sort(Comparable[] a)
    {
        int N = a.length;
        for (int i = 0; i < N; i++)
        {
            Comparable v = a[i];
            int lo = 0, hi = i;
            while (lo < hi)
            {
                int mid = lo + (hi - lo)/2;
                if(less(v,a[mid])) hi = mid;
                else               lo = mid + 1;
            }
//            exch(a,i,lo);
            for (int j = i; j > lo; --j)
            {
                a[j]  = a[j-1];
                View(a,j,j-1);
            }
            a[lo] = v;
        }
        assert isSorted(a);
    }

    public static void main(String[] args)
    {
        String[] a = test(100);
        sort(a);
        assert isSorted(a);
        show(a);
    }
}
