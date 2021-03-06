void merge(vector <int>&v1, int Firstindex, int m, int Lastindex);

void mergeSort(vector <int>&v1, int Firstindex, int Lastindex)
{
    if (Firstindex < Lastindex)
    {

        int m = Firstindex + (Lastindex - Firstindex) / 2;


        mergeSort(v1, Firstindex, m);
        mergeSort(v1, m + 1, Lastindex);

        merge(v1, Firstindex, m, Lastindex);

    }
}

void merge(vector <int>&v1, int Firstindex, int m, int Lastindex)
{
    int x;
    int y;
    int z;
    int sub1 = m - Firstindex + 1;
    int sub2 = Lastindex - m;


    int* First=new int[sub1];

    int* Second=new int[sub2];


    for (x = 0; x < sub1; x++) 
        First[x] = v1[Firstindex + x];
    for (y = 0; y < sub2; y++)
        Second[y] = v1[m + 1 + y];


    x = 0;
    y = 0;
    z = Firstindex;
    while (x < sub1 && y < sub2)
    {
        if (First[x] <= Second[y])
        {
            v1[z] = First[x];
            x++;
        }
        else
        {
            v1[z] = Second[y];
            y++;
        }
        z++;
    }
    while (x < sub1)
    {
        v1[z] = First[x];
        x++;
        z++;
    }
    while (y < sub2)
    {
        v1[z] = Second[y];
        y++;
        z++;
    }
}
int main()
{
    vector <int> v1;
    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(8);
    v1.push_back(10);
    v1.push_back(9);

    mergeSort(v1, 0, v1.size()-1);
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << endl;
    }
}
