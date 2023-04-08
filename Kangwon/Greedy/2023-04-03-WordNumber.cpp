#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

int main() {
	int cnt;
	std::unordered_map<char,int> hash_map;
	std::cin>>cnt;
	
	for(int i =0;i<cnt;i++){
		std::string str;
		int num = str.length();
		for(char c :str){
			num--;
			auto item = hash_map.find(c);
			if(item != hash_map.end()){
				hash_map[c] += std::pow(10,num);
			}else{
				hash_map[c] = std::pow(10,num);
			}
		}
	}

}