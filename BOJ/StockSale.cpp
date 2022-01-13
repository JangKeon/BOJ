#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#define CMD_INIT 1
#define CMD_BUY 2
#define CMD_SELL 3
#define CMD_CANCEL 4
#define CMD_BEST_PROFIT 5

extern void init();
extern int buy(int mNumber, int mStock, int mQuantity, int mPrice);
extern int sell(int mNumber, int mStock, int mQuantity, int mPrice);
extern void cancel(int mNumber);
extern int bestProfit(int mStock);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
    int numQuery;

    int mNumber, mStock, mQuantity, mPrice;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_BUY:
            scanf("%d %d %d %d", &mNumber, &mStock, &mQuantity, &mPrice);
            userAns = buy(mNumber, mStock, mQuantity, mPrice);
            std::cout << userAns << '\n';
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        case CMD_SELL:
            scanf("%d %d %d %d", &mNumber, &mStock, &mQuantity, &mPrice);
            userAns = sell(mNumber, mStock, mQuantity, mPrice);
            std::cout << userAns << '\n';
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        case CMD_CANCEL:
            scanf("%d", &mNumber);
            cancel(mNumber);
            break;
        case CMD_BEST_PROFIT:
            scanf("%d", &mStock);
            userAns = bestProfit(mStock);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}

int main()
{
    setbuf(stdout, NULL);
    //freopen("sample_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Stock {
    int mNumber;
    int mStock;
    int mQuantity;
    int mPrice;
    Stock() {};
    Stock(int mNumber, int mStock, int mQuantity, int mPrice) : mNumber(mNumber), mStock(mStock), mQuantity(mQuantity), mPrice(mPrice) {};
    bool operator<(const Stock s) const {
        if (mPrice == s.mPrice) {
            return mNumber > s.mNumber;
        }
        else {
            return mPrice < s.mPrice;
        }
    }
};

priority_queue <Stock> buypq[5], sellpq[5];
queue <int> History[5];


void init()
{
    priority_queue <Stock> empty, empty2;
    queue <int> empty3;
    for (int i = 0; i < 5; i++) {
        buypq[i] = empty;
        sellpq[i] = empty2;
        History[i] = empty3;
    }
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    Stock bs = Stock{ mNumber, mStock, mQuantity, mPrice };
    int remain_stock = mQuantity;
    if (sellpq[mStock - 1].empty()) {
        //std::cout << "buypq is empty\n";
        buypq[mStock - 1].push(Stock(mNumber, mStock, mQuantity, mPrice));
    }
    else {
        while (!sellpq[mStock - 1].empty()) {
            Stock ss = sellpq[mStock - 1].top();
            if (bs.mPrice >= ss.mPrice) {
                std::cout << "bs is bigger than ss" << '\n';
                if (bs.mQuantity > ss.mQuantity) {
                    bs.mQuantity -= ss.mQuantity;
                    sellpq[mStock - 1].pop();
                    History[mStock - 1].push(ss.mPrice);
                    std::cout << "mPrice : " << ss.mPrice << '\n';
                    remain_stock = bs.mQuantity;
                }
                else if (bs.mQuantity == ss.mQuantity) {
                    sellpq[mStock - 1].pop();
                    History[mStock - 1].push(ss.mPrice);
                    std::cout << "mPrice : " << ss.mPrice << '\n';
                    remain_stock = 0;
                }
                else {
                    ss.mQuantity -= bs.mQuantity;
                    remain_stock = 0;
                    break;
                }
            }
            else {
                //std::cout << "Else Clear" << '\n';
                buypq[mStock - 1].push(Stock(mNumber, mStock, mQuantity, mPrice));
                remain_stock = bs.mQuantity;
                break;
            }
        }
    }
    //std::cout << remain_stock << '\n';
    return remain_stock;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
    Stock ss = Stock{ mNumber, mStock, mQuantity, mPrice };
    int remain_stock = mQuantity;
    if (buypq[mStock - 1].empty()) {
        //std::cout << "sellpq is empty\n";
        sellpq[mStock - 1].push(Stock(mNumber, mStock, mQuantity, mPrice));
    }
    else {
        while (!buypq[mStock - 1].empty()) {
            Stock bs = buypq[mStock - 1].top();
            if (ss.mPrice <= bs.mPrice) {
                //std::cout << "Clear" << '\n';
                if (ss.mQuantity > bs.mQuantity) {
                    ss.mQuantity -= bs.mQuantity;
                    buypq[mStock - 1].pop();
                    sellpq[mStock - 1].push(Stock(mNumber, mStock, mQuantity, mPrice));
                    History[mStock - 1].push(bs.mPrice);
                    std::cout << "mPrice : " << bs.mPrice << '\n';
                    remain_stock = ss.mQuantity;

                }
                else if (ss.mQuantity == bs.mQuantity) {
                    buypq[mStock - 1].pop();
                    History[mStock - 1].push(bs.mPrice);
                    std::cout << "mPrice : " << bs.mPrice << '\n';
                    remain_stock = 0;
                }
                else {
                    bs.mQuantity -= ss.mQuantity;
                    remain_stock = 0;
                    break;
                }
            }
            else {
                sellpq[mStock - 1].push(Stock(mNumber, mStock, mQuantity, mPrice));
                remain_stock = bs.mQuantity;
                break;
            }
        }
    }
    //std::cout << remain_stock << '\n';
    return remain_stock;
}


void cancel(int mNumber)
{
    vector <Stock> Cancel;
    vector <int> Index;
    Stock bs, ss;
    bool inBuy = false, inSell = false;
    for (int i = 0; i < 5; i++) {
        while (!buypq[i].empty()) {
            bs = buypq[i].top();
            if (mNumber == bs.mNumber) {
                inBuy = true;
                inSell = false;
                break;
            }
            else {
                inBuy = false;
                inSell = true;
            }
            Index.push_back(i + 1);
            Cancel.push_back(Stock(bs.mNumber, bs.mStock, bs.mQuantity, bs.mPrice));
            buypq[i].pop();
        }
    }
    while (!Cancel.empty()) {
        int temp = Index.front();
        buypq[temp].push(Cancel.front());
        Cancel.pop_back();
        Index.pop_back();
    }


    std::cout << "inBuy : " << inBuy << '\n';
    if (inBuy) {
        cout << "Go if\n";
        for (int i = 0; i < 5; i++) {
            cout << "buypq Empty?" << buypq[i].empty();
            while (!buypq[i].empty()) {
                bs = buypq[i].top();
                cout << bs.mNumber << '\n';
                if (mNumber == bs.mNumber) {
                    buypq[i].pop();
                }
                else {
                    Cancel.push_back(Stock(bs.mNumber, bs.mStock, bs.mQuantity, bs.mPrice));
                    buypq[i].pop();
                }
            }
        }
        for (int i = 0; i < Cancel.size(); i++) {
            std::cout << "Cancel Added" << '\n';
            buypq[Cancel.front().mStock - 1].push(Cancel.front());
            Cancel.pop_back();
        }
    }
    else {
        cout << "Go Else\n";
        for (int i = 0; i < 5; i++) {
            while (!sellpq[i].empty()) {
                ss = sellpq[i].top();
                if (mNumber == ss.mNumber) {
                    sellpq[i].pop();
                }
                else {
                    Cancel.push_back(Stock(ss.mNumber, ss.mStock, ss.mQuantity, ss.mPrice));
                    sellpq[i].pop();
                }
            }
        }
        for (int i = 0; i < Cancel.size(); i++) {
            sellpq[Cancel.front().mStock - 1].push(Cancel.front());
            Cancel.pop_back();
        }
    }
}

int bestProfit(int mStock)
{
    queue <int> Save;
    int i = 0, temp = History[mStock - 1].size();
    int* Array = new int[temp];
    while (!History[mStock - 1].empty()) {
        Array[i] = History[mStock - 1].front();
        Save.push(History[mStock - 1].front());
        History[mStock - 1].pop();
        std::cout << "Array[" << i << "] = " << Array[i] << '\n';
        ++i;

    }
    while (!Save.empty()) {
        History[mStock - 1].push(Save.front());
        Save.pop();
    }
    int max = 0, min = Array[0];
    for (int i = 1; i < temp; i++) {
        if (Array[i] < min) {
            min = Array[i];
            continue;
        }
        if (max < Array[i] - min) {
            max = Array[i] - min;
        }
    }
    std::cout << "max" << max << '\n';
    return max;
}