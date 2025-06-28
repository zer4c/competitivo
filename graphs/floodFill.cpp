
int n, m;//dimensiones
int dir[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}}; // direcciones
vector<vector<int>> tab, visi;
int floodfill(int x, int y){
    if (x < 0 || y < 0 || x >= n || y >= m || visi[x][y] || tab[x][y] == 0)
        return;
    visi[x][y] = 1;
    int ret = 1;
    for (int i = 0; i < 4; i++)
        ret += floodfill(x + dir[0][i], y + dir[1][i]);
    return ret;
}