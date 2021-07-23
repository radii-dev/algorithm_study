#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct room {
	int room_id;
	vector<int>* neighbor;
};

vector<int> findWay(vector<room>* rooms, int start_room_num, int end_room_num) {
	stack<int> find_stack;
	vector<int> path;
	path.push_back(start_room_num - 1);
	int room_iter = start_room_num - 1;
	int prev_iter = start_room_num - 1;
	do {
		int st_size = find_stack.size();
		for (int i = 0; i < rooms->size(); i++) {
			if (rooms->at(room_iter).neighbor->at(i) != 0 && i != prev_iter)
				find_stack.push(i);
		}
		if (find_stack.size() == st_size) { // dead_end
			path.pop_back();
		}
		else {
			path.push_back(find_stack.top());
		}
		prev_iter = room_iter;
		room_iter = find_stack.top();
		find_stack.pop();
	} while (room_iter != end_room_num - 1);
	return path;
}

int findShortestPath(vector<int> path, vector<room>* rooms) {
	vector<int> subPath;
	subPath.clear();
	int dist_sum = 0;
	vector<int>::iterator path_it_L = path.begin();
	vector<int>::iterator path_it_R = path.end() - 1;
	bool process_end = false;
	do {
		vector<int>::iterator path_it_L_p = path_it_L + 1;
		vector<int>::iterator path_it_R_m = path_it_R - 1;
		int length_L = rooms->at(*path_it_L).neighbor->at(*path_it_L_p);
		int length_R = rooms->at(*path_it_R).neighbor->at(*path_it_R_m);
		if (length_L == length_R) {
			dist_sum += length_L;
			subPath.assign(path_it_L_p, path_it_R_m);
			if (*subPath.begin() != *(subPath.end() - 1))
				dist_sum += findShortestPath(subPath, rooms);
			break;
		}
		else if (length_L > length_R) {
			dist_sum += length_R;
			path_it_R--;
		}
		else if (length_L < length_R) {
			dist_sum += length_L;
			path_it_L++;
		}
		if (*path_it_L == *path_it_R_m)
			process_end = true;
	} while (!process_end);
	return dist_sum;
}

int findShortestPath(vector<room>* rooms, int start_room_num, int end_room_num) {
	vector<int> path = findWay(rooms, start_room_num, end_room_num);
	vector<int> subPath;
	subPath.clear();
	int dist_sum = 0;
	vector<int>::iterator path_it_L = path.begin();
	vector<int>::iterator path_it_R = path.end() - 1;
	bool process_end = false;
	do {
		vector<int>::iterator path_it_L_p = path_it_L + 1;
		vector<int>::iterator path_it_R_m = path_it_R - 1;
		int length_L = rooms->at(*path_it_L).neighbor->at(*path_it_L_p);
		int length_R = rooms->at(*path_it_R).neighbor->at(*path_it_R_m);
		if (length_L == length_R) {
			dist_sum += length_L;
			subPath.assign(path_it_L_p, path_it_R_m);
			/*
			vector<int> subPath;
			subPath.clear();
			subPath.assign(path.begin() + iterToptr(path, path_it_L), path.begin() + iterToptr(path, path_it_R));
			path.erase(path_it_L);
			path.erase(path_it_R);
			*/
			if (*subPath.begin() != *(subPath.end() - 1))
				dist_sum += findShortestPath(subPath, rooms);
			break;
		}
		else if (length_L > length_R) {
			dist_sum += length_R;
			path_it_R--;
		}
		else if (length_L < length_R) {
			dist_sum += length_L;
			path_it_L++;
		}
		if (*path_it_L == *path_it_R_m)
			process_end = true;
	} while (!process_end);
	return dist_sum;
}

int main() {
	int total_room;
	int start_room_num, end_room_num;
	cin >> total_room >> start_room_num >> end_room_num;
	vector<room>* rooms = new vector<room>(total_room);
	room start_room, end_room;
	for (int i = 0; i < total_room; i++) {
		rooms->at(i).room_id = i;
		rooms->at(i).neighbor = new vector<int>(total_room);
		for (int j = 0; j < total_room; j++) 
			rooms->at(i).neighbor->at(j) = 0;
	}
	for (int i = 0; i < total_room - 1; i++) {
		int left_ends_room, right_ends_room, len;
		cin >> left_ends_room >> right_ends_room >> len;
		rooms->at(left_ends_room - 1).neighbor->at(right_ends_room - 1) = len;
		rooms->at(right_ends_room - 1).neighbor->at(left_ends_room - 1) = len;
	}
	cout << findShortestPath(rooms, start_room_num, end_room_num);
}