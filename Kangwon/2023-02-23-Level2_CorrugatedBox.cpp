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
	//���� Ǯ�� �ð��ʰ� �߻� 

	int answer = 0;// ä���־���� order ��ġ
	std::vector<int> save1;//����
	save1.push_back(10000001);
	for (int i = 1; i < order.size() + 1; i++) {
		if (order[answer] == i) {//�ٷ� ó��
			answer += 1;
		}
		else if (order[answer] == save1.back()) {// ���������̳ʿ��� �ٷ�ó��
			save1.pop_back();
			answer += 1;
			i -= 1;
		}
		else {
			save1.push_back(i);
		}
	}
	//������ �ݺ��ϸ鼭 �ٷ� ó���� �� �ִ� �κа� ���� �����̳ʸ� ���� ó���� �κ��� ó�����ش�.
	//���� �����̳ʸ� ���� ó������ ���� �ѹ� �� �ݺ����ش�. 
	

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
	// ���� ���� �����̳ʸ� �ݺ��ذ��� ó���Ѵ�. 
	//���ͳ� ������ Ǯ�� 
}

int main() {

	std::vector<int> tmp = {4,3,1,2,5};
	std::cout<<solution(tmp);
	return 0;
}