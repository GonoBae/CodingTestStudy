#include <iostream>
#include <vector>

int solution(std::vector<int> order) {
    int answer = 0;
	//int num = 1;
	//int size = order.size();
	//std::vector<int> container;

	//while (true) {
	//	if (order.size() == 0) break;

	//	if (container.size() != 0) {
	//		if(container[container.size() - 1] == order[0]) {
	//			container.pop_back();
	//			order.erase(order.begin());
	//			answer++;
	//			continue;
	//		}
	//		else if (num > size) break;
	//	}
	//	
	//	if (num == order[0]) {
	//		order.erase(order.begin());
	//		num++;
	//		answer++;
	//	}
	//	else {
	//		container.push_back(num);
	//		num++;
	//	}
	//}
	//기존 풀이 시간초과 발생 

	int answer = 0;// 채워넣어야할 order 위치
	std::vector<int> save1;//보조
	save1.push_back(10000001);
	for (int i = 1; i < order.size() + 1; i++) {
		if (order[answer] == i) {//바로 처리
			answer += 1;
		}
		else if (order[answer] == save1.back()) {// 보조컨테이너에서 바로처리
			save1.pop_back();
			answer += 1;
			i -= 1;
		}
		else {
			save1.push_back(i);
		}
	}
	//순서를 반복하면서 바로 처리할 수 있는 부분과 보조 컨테이너를 통해 처리할 부분을 처리해준다.
	//보조 컨테이너를 통해 처리했을 때는 한번 더 반복해준다. 
	

	while (save1.size() != 1) {
		if (save1.back() == order[answer]) {
			answer += 1;
			save1.pop_back();
		}
		else {
			break;
		}
	}
    return answer;
	// 남은 보조 컨테이너를 반복해가며 처리한다. 
	//인터넷 참고한 풀이 
}

int main() {

	std::vector<int> tmp = {4,3,1,2,5};
	std::cout<<solution(tmp);
	return 0;
}