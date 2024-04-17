//#include <iostream>
//#include <vector>
//#include <random>
//#include <Windows.h>
//#include <queue>
//
//using namespace std;
//
//#define SIZE 24
//#define MINE 10
//
//int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//
//vector<pair<int, int>> minepos;
//
//int getRandomNum() {
//    random_device rand;
//    mt19937 gen(rand());
//    uniform_int_distribution<int> dis(1, SIZE);
//
//    return dis(gen);
//}
//
//void setting(vector<vector<int>>& map, vector<vector<int>>& open) {
//    int minecount = MINE;
//    while (true) {
//        if (minecount == 0) break;
//        int y = getRandomNum(), x = getRandomNum();
//        if (map[y][x] == 0) {
//            map[y][x] = -1;
//            minepos.push_back({ y, x });
//            minecount--;
//        }
//    }
//    for (pair<int, int> i : minepos) {
//        int y = i.first, x = i.second;
//        open[y][x] = 0;
//        if (map[y][x] == -1) {
//            for (int k = 0; k < 8; k++) {
//                int ny = y + dy[k], nx = x + dx[k];
//                if (ny >= 1 && ny <= SIZE && nx >= 1 && nx <= SIZE) {
//                    if (map[ny][nx] >= 0) map[ny][nx]++;
//                }
//            }
//        }
//    }
//    for (int y = 0; y <= SIZE; y++) {
//        for (int x = 0; x <= SIZE; x++) {
//            open[y][x] = 0;
//        }
//    }
//}
//
//void printmap(vector<vector<int>>& map, vector<vector<int>>& open) {
//    system("cls");
//    for (int y = 0; y <= SIZE; y++) {
//        for (int x = 0; x <= SIZE; x++) {
//            if (y == 0 && x == 0) {
//                cout << "   ";
//                continue;
//            }
//            else if (y == 0) {
//                if (x >= 10) cout << " " << x;
//                else cout << "  " << x;
//                continue;
//            }
//            else if (x == 0) {
//                if (y >= 10) cout << " " << y;
//                else cout << "  " << y;
//                continue;
//            }
//            if (open[y][x] == 1) {
//                cout << "  " << map[y][x];
//            }
//            else if (open[y][x] == 0) {
//                cout << "  X";
//            }
//            else if (open[y][x] == 2) {
//                cout << "  V";
//            }
//            else if (open[y][x] == 9) {
//                cout << "  *";
//            }
//        }
//        cout << "\n";
//    }
//}
//
//void findblank(vector<vector<int>>& map, vector<vector<int>>& open, int y, int x) {
//    queue<pair<int, int>> save;
//    save.push({ y, x });
//    open[y][x] = 1;
//    while (!save.empty()) {
//        int cy = save.front().first, cx = save.front().second;
//        save.pop();
//        for (int k = 0; k < 8; k++) {
//            int ny = cy + dy[k], nx = cx + dx[k];
//            if (ny >= 1 && ny <= SIZE && nx >= 1 && nx <= SIZE) {
//                if (map[ny][nx] != -1 && open[ny][nx] == 0) {
//                    open[ny][nx] = 1;
//                    if (map[ny][nx] == 0) {
//                        save.push({ ny, nx });
//                    }
//                }
//            }
//        }
//    }
//}
//
//int openmap(vector<vector<int>>& map, vector<vector<int>>& open, int y, int x) {
//    if (map[y][x] == -1) {
//        for (pair<int, int> mine : minepos) {
//            int y = mine.first, x = mine.second;
//            open[y][x] = 9;
//        }
//        return -1;
//    }
//    else if (map[y][x] == 0) {
//        findblank(map, open, y, x);
//        return 1;
//    }
//    else {
//        open[y][x] = 1;
//        return 1;
//    }
//}
//
//int setflg(vector<vector<int>>& map, vector<vector<int>>& open, int y, int x) {
//    // 1 : Áö·Ú¸¦ ±ê¹ß¿¡ ²È¾Ò´Ù. 2 : ±ê¹ßÀ» »Ì¾Ò´Ù. 3 : ±ê¹ßÀ» »Ì¾Ò´Ù ±Ùµ¥ Áö·ÚÂÊÀÌ³×? 4: Áö·Ú°¡ ¾Æ´Ñ°÷¿¡ ±ê¹ßÀ» ²Å¾Ò´Ù.
//    if (open[y][x] == 2) {
//        open[y][x] = 0;
//        if (map[y][x] == -1) {
//            return 3;
//        }
//        else {
//            return 2;
//        }
//    }
//    else if (open[y][x] == 0) {
//        open[y][x] = 2;
//        if (map[y][x] == -1) {
//            return 1;
//        }
//        else {
//            return 4;
//        }
//    }
//}
//
//int main()
//{
//    vector<vector<int>> map(SIZE + 1, vector<int>(SIZE + 1, 0)); // mine = -1, 0 = blank
//    vector<vector<int>> open(SIZE + 1, vector<int>(SIZE + 1, 0));
//    setting(map, open);
//    char order;
//    int y, x, mineflgcount = 0, curflgcount = 0;
//    while (true) {
//        printmap(map, open);
//        cout << "--------- Çàµ¿, yÁÂÇ¥, x ÁÂÇ¥ ¼øÀ¸·Î ÀÔ·ÂÇØÁÖ¼¼¿ä. (°¡´ÉÇÑ Çàµ¿ : o -> ¿ÀÇÂ, f -> ±ê¹ß)--------------\n";
//        cin >> order >> y >> x;
//        if (order == 'o') {
//            if (open[y][x] == 0) {
//                int res = openmap(map, open, y, x);
//                if (res == -1) {
//                    printmap(map, open);
//                    cout << "----------°ÔÀÓ ¿À¹ö (Àç½ÃÀÛ? y / n)--------------\n";
//                    cin >> order;
//                    if (order == 'y') {
//                        mineflgcount = 0, curflgcount = 0;
//                        setting(map, open);
//                        continue;
//                    }
//                    else if (order == 'n') {
//                        break;
//                    }
//                }
//            }
//        }
//        else if (order == 'f') {
//            if (open[y][x] != 0 && open[y][x] != 2) continue;
//            int res = setflg(map, open, y, x);
//            switch (res) {
//            case 1:
//                curflgcount++;
//                mineflgcount++;
//                break;
//            case 2:
//                curflgcount--;
//                break;
//            case 3:
//                mineflgcount--;
//                curflgcount--;
//                break;
//            case 4:
//                curflgcount++;
//            }
//            if (mineflgcount == MINE && curflgcount == mineflgcount) {
//                printmap(map, open);
//                cout << "------------°ÔÀÓ ½Â¸® (Àç½ÃÀÛ? y / n)------------\n";
//                cin >> order;
//                if (order == 'y') {
//                    mineflgcount = 0, curflgcount = 0;
//                    setting(map, open);
//                    continue;
//                }
//                else if (order == 'n') {
//                    break;
//                }
//            }
//        }
//    }
//}