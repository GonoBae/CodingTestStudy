#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int main() {
	bool box[26]={0,};
	std::vector<char> vec;
	std::string str;
	std::cin>>str;
	
	int cnt=0;
	for(char c:str){
		if(box[c-65]){
			box[c-65] = false;
			cnt--;
			vec.push_back(c);
		}else{
			box[c-65] = true;
			cnt++;
		}
	}
	if(cnt>1){
		std::cout << "I'm Sorry Hansoo" << std::endl;
	}else{
		std::sort(vec.begin(),vec.end());	
		for(int i =0;i< vec.size();i++){
			std::cout<<vec[i];	
		}					
		
		for(int i =0;i<26;i++){
			if(box[i]){
				std::cout<< static_cast<char>(65+i);	
			}
		}

		for(int i =vec.size()-1;i>=0;i--){
			std::cout<<vec[i];	
		}
				
	}
}