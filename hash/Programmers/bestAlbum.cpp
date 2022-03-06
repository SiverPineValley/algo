// Programmers
// hash - 베스트 앨범
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 내림차순 정렬
bool cmp_total(const pair<string,int>& left, const pair<string,int>& right) {
	return right.second < left.second;
}

// 재생수 같으면, 고유번호의 오름차순
// 재생수는 내림차순
bool cmp_each(const pair<int,int>& left, const pair<int,int>& right) {
    if (left.first == right.first) {
        return left.second < right.second;
    }
    return right.first < left.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int size = genres.size();
    vector<int> answer;
    map<string,int> genre_total;
    map<string,vector<pair<int,int>>> genre_play;
    
    // map 생성
    for(int i = 0; i < size; i++) {
        if (genre_total.count(genres[i]) == 0) {
            genre_total[genres[i]] = plays[i];
            vector<pair<int,int>> temp;
            temp.push_back(make_pair(plays[i],i));
            genre_play[genres[i]] = temp;
            continue;
        }
        genre_total[genres[i]] = genre_total[genres[i]] + plays[i];
        auto temp = genre_play[genres[i]];
        temp.push_back(make_pair(plays[i],i));
        genre_play[genres[i]] = temp;
    }
    
    // 장르별 정렬
    vector<pair<string, int> > arr;
    for (const auto &item : genre_total) {
        arr.emplace_back(item);
    }
    sort(arr.begin(), arr.end(), cmp_total);
    
    // answer에 담기
    for(auto it = arr.begin(); it != arr.end(); it++) {
        auto each = genre_play[it->first];
        sort(each.begin(), each.end(), cmp_each);
        int idx = 0;
        int each_size = each.size();
        while(idx < 2 && idx < each_size) {
            auto each_value = each[idx].second;
            answer.push_back(each_value);
            idx++;
        }
    }
    
    return answer;
}