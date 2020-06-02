#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMinEffort' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY C as parameter.
 */


bool check(int x, int y, int n, int m){
    if(x < 0 or x >= n or y < 0 or y >= m) return false;
    return true;
}

int find(int x, vector<int> &id){
    
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void _union(int x, int y, vector<int> &id){
    x = find(x, id);
    y = find(y, id);
    id[x] = id[y];
}

    


int getMinEffort(vector<vector<int>> C) {
    
    int n = C.size();
    int m = C[0].size();
    int s = n * m;
    
    vector< pair<int, pair<int, int> > > edges;
    vector<int> id(s, 0);
    vector<int> di({-1, 0, 1, 0}), dj({0, 1, 0, -1});
    
    for(int i = 0;i < s; i++) id[i] = i;
    
    for(int i = 0;i < n; i++){
        for(int j = 0;j < m; j++){
            for(int k = 0;k < 4; k++){
                if(check(i + di[k], j + dj[k], n, m)){
                    int x = (i * m) + j;
                    int y = ((i + di[k]) * m) + (j + dj[k]);
                    int w = abs(C[i][j] - C[i + di[k]][j + dj[k]]);
                    edges.push_back({w, {x, y}});
                }
            }
        }
    }
    
    sort(edges.begin(), edges.end());
    
    int ans = 0;
    
    for(auto e : edges){
        int w = e.ff;
        int x = e.ss.ff;
        int y = e.ss.ss;
        
        cout << x << " " << y << " " << w  << endl;
        
        if(find(x, id) != find(y, id)){
            
            _union(x, y, id);
            
            if(find(0, id) == find(s-1, id)){
                ans = w;
                break;
            }
        }
    }
    
    return ans;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(m);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int answer = getMinEffort(arr);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
