#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
	int x = 0;
	int y = 0;
};
/*
queue<point> scan(uint8_t map[16][16], queue<point> qu, point target, point prev) {
	point left = target, up = target, right = target, down = target;
	left.x--;
	up.y--;
	right.x++;
	down.y++;
	if (((left.x != prev.x) || (left.y != prev.y)) && (left.x >= 0) && (map[left.x][left.y] == '0')) qu.push(left);
	if (((up.x != prev.x) || (up.y != prev.y)) && (up.y >= 0) && (map[up.x][up.y] == '0')) qu.push(up);
	if (((right.x != prev.x) || (right.y != prev.y)) && (right.x < 16) && (map[right.x][right.y] == '0')) qu.push(right);
	if (((down.x != prev.x) || (down.y != prev.y)) && (down.y < 16) && (map[down.x][down.y] == '0')) qu.push(down);
	return qu;
}

int BFS(uint8_t map[16][16], point start, point end) {
	queue<point> qu;
	point cur = start;
	point prev = start;
	qu = scan(map, qu, cur, prev);
	while (!qu.empty()) {
		prev = cur;
		cur = qu.front();
		qu.pop();
		if (map[cur.x][cur.y] == '3') break;
		qu = scan(map, qu, cur, prev);
	}
	if (map[cur.x][cur.y] == 3) return 1;
	else return 0;
}
*/
queue<point> scan(uint8_t map[16][16], queue<point> qu, point target, bool vis[16][16]) {
	point left = target, up = target, right = target, down = target;
	left.x--;
	up.y--;
	right.x++;
	down.y++;
	if ((vis[left.x][left.y] == false) && (left.x >= 0) && ((map[left.x][left.y] == '0') || (map[left.x][left.y] == '3'))) qu.push(left);
	if ((vis[up.x][up.y] == false) && (up.y >= 0) && ((map[up.x][up.y] == '0') || (map[up.x][up.y] == '3'))) qu.push(up);
	if ((vis[right.x][right.y] == false) && (right.x < 16) && ((map[right.x][right.y] == '0') || (map[right.x][right.y] == '3'))) qu.push(right);
	if ((vis[down.x][down.y] == false) && (down.y < 16) && ((map[down.x][down.y] == '0') || (map[down.x][down.y] == '3'))) qu.push(down);
	return qu;
}

int BFS(uint8_t map[16][16], point start, point end) {
	queue<point> qu;
	point cur = start;
	bool visited[16][16] = { false, };
	qu = scan(map, qu, cur, visited);
	while (!qu.empty()) {
		visited[cur.x][cur.y] = true;
		cur = qu.front();
		qu.pop();
		if ((cur.x == end.x) && (cur.y == end.y)) break;
		qu = scan(map, qu, cur, visited);
	}
	if ((cur.x == end.x) && (cur.y == end.y)) return 1;
	else return 0;
}

int main() {
	int num = 1;
	for (int i = 0; i < 10; i++) {
		uint8_t src[16][16] = { 0, };
		uint8_t dummy;
		int result;
		point start, end;
		cin >> num;
		scanf("%c", &dummy);
		for (int j = 0; j < 16; j++) {
			// scanf("%c", &dummy);				온라인 컴파일러가 돌린 예제는 배열입력에서 행간에 \n이 포함되어있엇음
			for (int k = 0; k < 16; k++) {
				scanf("%c", &src[k][j]);
				if (src[k][j] == '2') {
					start.x = k;
					start.y = j;
				}
				else if (src[k][j] == '3') {
					end.x = k;
					end.y = j;
				}
			}
		}

		result = BFS(src, start, end);
		cout << "#" << num << " " << result << endl;
	}
} 