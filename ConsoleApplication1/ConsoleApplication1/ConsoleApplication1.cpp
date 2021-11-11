#include <iostream>;
#include <vector>;
#include <math.h>;
using namespace std;



bool solution(const int M, bool* m[])
{
    int start_pos[] = { 0, 0 }, end_pos[] = { M - 1, M - 1 };
    vector <vector<int>> arr, end_mas, way, mas;
    arr.assign(0, vector<int>(2)), end_mas.assign(0, vector<int>(2)), way.assign(0, vector<int>(2)), mas.assign(0, vector<int>(2));;
    end_mas.push_back({ 0, 0 }), way.push_back({ 0, 0 });
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        { 
            if ((m[i][j] != 0) && (m[i][j] != 1))
            {
                return false;
            }
            if (m[i][j] == 1)
            {
                arr.push_back({ i, j });
            }
        }
    }
    int size = arr.size();
    if ((arr[0][0] != start_pos[0] || arr[0][1] != start_pos[1]) || (arr[size-1][0] != end_pos[0] || arr[size-1][1] != end_pos[1]))
    { 
        return false;
    }
    bool Flag = false;
    while (true)
    {
        for (int colum = 0; colum < way.size(); colum++)
        {
            for (int i = 0; i < signed(arr.size()); i++)
            {
                for (int end = 0; end < end_mas.size(); end++)
                {
                    if (arr[i] == end_mas[end])
                    {
                        Flag = true;
                    }
                }
                if ((way[colum][0] == arr[i][0] || way[colum][1] == arr[i][1])
                    && (abs((way[colum][0] + way[colum][1]) - (arr[i][0] + arr[i][1])) == 1)
                    && (Flag != true))
                {
                    mas.push_back(arr[i]);
                    end_mas.push_back(arr[i]);
                }
                Flag = false;
            }
        }
        way = mas;
        mas.assign(0, vector<int>(2));
        if (way.size() == 0)
        { 
            return false;
        }
        for (int i = 0; i < way.size(); i++)
        {
            if (way[i][0] == end_pos[0] && way[i][1] == end_pos[1])
            {
                return true;
            }
        }
    }
}
int main()
{
    const int M = 6;
    bool m[M][M] = {{ 1, 0, 1, 1, 1, 0 },
                    { 1, 0, 1, 1, 1, 0 },
                    { 1, 1, 1, 1, 0, 0 },
                    { 0, 0, 1, 0, 1, 0 },
                    { 0, 0, 1, 1, 1, 0 },
                    { 1, 1, 0, 1, 1, 1 } };
    bool* mas[M];
    for (int i = 0; i < M; i++)
    {
        mas[i] = m[i];
    }
    cout<<solution(M, mas);
}


