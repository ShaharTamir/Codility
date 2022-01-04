public class FloodDepth
{
    public int solution(int[] A)
    {
        int maxIndex = FindMaxIndex(A);
        int maxLeftIndex = SearchLeftMaxIndex(A, maxIndex);
        int maxRightIndex = SearchRightMaxIndex(A, maxIndex);


        return MaxDepth(A, maxIndex, maxLeftIndex, maxRightIndex);
    }

     private int MaxDepth(int[] A, int maxIndex, int maxLeftIndex, int maxRightIndex)
    {
        if(A.length < 3 || maxIndex == -1)
            return 0;

        int leftDepth = -1;
        int rightDepth = -1;

        if(maxLeftIndex != -1)
            leftDepth = CheckDepth(A, maxLeftIndex, maxIndex, A[maxLeftIndex]);
        if(maxRightIndex != -1)
            rightDepth = CheckDepth(A, maxIndex + 1 ,maxRightIndex, A[maxRightIndex]);

        return Math.max(leftDepth, Math.max(rightDepth, 
        Math.max(MaxDepth(A, maxLeftIndex, SearchLeftMaxIndex(A, maxLeftIndex), -1), 
                MaxDepth(A, maxRightIndex, -1, SearchRightMaxIndex(A, maxRightIndex))))); 
    }

    private int CheckDepth(int[] A, int left, int right, int lim)
    {
        int res = 0;

        for(int i = left; i < right; ++i)
        {
            res = Math.max(res, lim - A[i]);
        }

        return res;
    }

    private int SearchLeftMaxIndex(int[] A, int rightLim)
    {
        int res = -1;
        int max = 0;

        for(int i = 0; i < rightLim; ++i)
        {
            if(A[i] >= max)
            {
                res = i;
                max = A[i];
            }
        }

        return res;
    }

    private int SearchRightMaxIndex(int[] A, int leftLim)
    {
        int res = -1;
        int max = 0;

        for(int i = A.length - 1; i > leftLim; --i)
        {
            if(A[i] >= max)
            {
                res = i;
                max = A[i];
            }
        }

        return res;
    }

    private int FindMaxIndex(int[] A)
    {
        int res = 0;
        int max = 0;

        for(int i = 0; i < A.length; ++i)
        {
            if(A[i] > max)
            {
                res = i;
                max = A[i];
            }
        }

        return res;
    }
}