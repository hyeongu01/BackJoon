/*
    https://www.acmicpc.net/problem/1012
*/

#include <iostream>
#include <queue>
#include <cstring>

struct cabbage_loc_group {
    int x;
    int y;
    int group = 0;
};

int main() {
    int T;
    std::cin >> T;
    int answers[T];

    // T번 반복
    for (int j = 0; j < T; j++) {
        int M, N, K;
        std::cin >> M >> N >> K;

        // 배추밭 상태 저장하는 2차원 배열 선언 후 0으로 초기화
        int field[M][N];
        memset(field, -1, sizeof(field));

        // cabage location group list 생성
        cabbage_loc_group loc_group_list[K];

        // 배추 위치 입력받아 해당 자리에 배추번호 할당
        for (int i =0; i < K; i++) {
            int x, y;
            std::cin >> x >> y;
            field[x][y] = i;

            // location group list에 위치 저장
            loc_group_list[i].x = x;
            loc_group_list[i].y = y;
        }

        // 그룹 탐지할 큐 생성
        std::queue<int> q;

        int current_group = 1;
        for (int i = 0; i < K; i++) {
            // 이번 양배추 그룹이 없다면
            if (loc_group_list[i].group == 0) {
                // 그룹이 없다면 행동 추가
                q.push(i);
                loc_group_list[i].group = current_group;

                //지금 그룹을 모두 탐색
                while (q.empty() != true) {
                    // q의 맨 앞 항목 pop()
                    int current_cab_id = q.front();
                    q.pop();

                    int cab_x = loc_group_list[current_cab_id].x;
                    int cab_y = loc_group_list[current_cab_id].y;

                    // current_cab의 인접한 field 확인 후 추가
                    if (cab_x > 0) {
                        int temp_cab = field[cab_x-1][cab_y];
                        if (temp_cab != -1 && loc_group_list[temp_cab].group == 0) {
                            q.push(temp_cab);
                            loc_group_list[temp_cab].group = current_group;
                        }
                    }
                    if (cab_x < M-1) {
                        int temp_cab = field[cab_x+1][cab_y];
                        if (temp_cab != -1 && loc_group_list[temp_cab].group == 0) {
                            q.push(temp_cab);
                            loc_group_list[temp_cab].group = current_group;
                        }
                    }
                    if (cab_y > 0) {
                        int temp_cab = field[cab_x][cab_y-1];
                        if (temp_cab != -1 && loc_group_list[temp_cab].group == 0) {
                            q.push(temp_cab);
                            loc_group_list[temp_cab].group = current_group;
                        }
                    }
                    if (cab_y < N-1) {
                        int temp_cab = field[cab_x][cab_y+1];
                        if (temp_cab != -1 && loc_group_list[temp_cab].group == 0) {
                            q.push(temp_cab);
                            loc_group_list[temp_cab].group = current_group;
                        }
                    }
                }
                current_group ++;
            }
        }
        answers[j] = current_group-1;
    }

    // 결과 출력
    for (int answer: answers) {
        std::cout << answer << "\n";
    }

    return 0;
}
