//
// Created by Liao Changzeng on 2019/4/2.
//


/*
 * 一副从1到n的牌,每次从牌堆顶取一张放桌子上,再取一张放牌堆底,直到手里没有牌.最后桌子上的牌是从1到n有序,设计程序,输入n,输出牌堆的顺序数组
 */

#include <queue>
#include <iostream>


using namespace std;


void cards_order(int cards_num, deque<int> &order_queue){
    for(auto ind=cards_num; ind>=1; ind--){
        if(!order_queue.empty()){
            order_queue.push_front(order_queue.back());
            order_queue.pop_back();
        }
        order_queue.push_front(ind);
    }
}


int main(){
    int cards_num; cin>>cards_num;
    deque<int> order_queue;
    cards_order(cards_num, order_queue);
    for(auto val : order_queue){
        cout<<val<<endl;
    }
}
