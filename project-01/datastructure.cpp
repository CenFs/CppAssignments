#include "datastructure.hpp"
#include <string>
using namespace std;

Datastructure::Datastructure() {
}

Datastructure::~Datastructure() {
    mkts_.clear();
}


bool smaller_name(string a, string b) {
    return a < b;
}

bool smaller_price(float a, float b) {
    return a < b;
}

bool smaller_product(Product a, Product b) {
    return a.name < b.name;
}

void Datastructure::addProduct(string mkt_name, string location, Product pdt) {
    if (pdtExist(mkt_name, location, pdt) == NEW_LOCATION) {
        // cerr << "NEW MARKET/LOCATION" << endl;
        vector<Product> tmp;
        tmp.push_back(pdt);
        mkts_[mkt_name][location] = tmp;
    } else if (pdtExist(mkt_name, location, pdt) == NEW_PRODUCT) {
        // cerr << "NEW PRODUCT" << endl;
        mkts_[mkt_name][location].push_back(pdt);
    } else if (pdtExist(mkt_name, location, pdt) == NEW_PRODUCT_PRICE) {
        // cerr << "UPDATE PRODUCT PRICE" << endl;
        mkts_[mkt_name][location].erase(find_if(
                                            mkts_[mkt_name][location].begin(),
                                            mkts_[mkt_name][location].end(),
                                            [pdt](const Product p){return pdt.name == p.name;}));
        mkts_[mkt_name][location].push_back(pdt);
    } else if (pdtExist(mkt_name, location, pdt) == ALL_EXIST) {
        // cerr << "ALL EXIST" << endl;
    }
}

int Datastructure::pdtExist(string mkt_name, string location, Product pdt) {
    if (mkts_.find(mkt_name) == mkts_.end() || mkts_[mkt_name].find(location) == mkts_[mkt_name].end()) {
        // cerr << "- new market or new location" << endl;
        return NEW_LOCATION;
    } else {
        auto iter = find_if(mkts_[mkt_name][location].begin(), mkts_[mkt_name][location].end(),
                            [pdt](const Product p){return p.name == pdt.name;});
        if (iter == mkts_[mkt_name][location].end()) {
            // cerr << "- market exists, location exists, no product." << endl;
            return NEW_PRODUCT;
        } else {
            auto iter = find_if(mkts_[mkt_name][location].begin(), mkts_[mkt_name][location].end(),
                                [pdt](const Product p) {
                if (p.name == pdt.name && p.price == pdt.price) return true;
                return false;
            });
            if (iter == mkts_[mkt_name][location].end()) {
                // cerr << "- update product price." << endl;
                return NEW_PRODUCT_PRICE;
            } else {
                // cerr << "- all exist." << endl;
                return ALL_EXIST;
            }
        }
    }
}

void Datastructure::chains() {
    auto iter = mkts_.begin();
    while (iter != mkts_.end()) {
        cout << iter->first << endl;
        iter++;
    }
    /*
    vector<string> chains;
    auto iter = mkts_.begin();
    while (iter != mkts_.end()) {
        chains.push_back(iter->first);
        iter++;
    }
    sort(chains.begin(), chains.end(), smaller_name);
    for (int i = 0; i < chains.size(); i++) {
        cout << chains.at(i) << endl;
    }*/
}


void Datastructure::stores(string chain_name) {
    auto iter = mkts_[chain_name].begin();
    if (iter == mkts_[chain_name].end()) {
        cout << "Error: No such a chain!"<< endl;
    } else {
        while (iter != mkts_[chain_name].end()) {
            cout << iter->first << endl;
            iter++;
        }
    }
}


void Datastructure::cheapest(string pdt_name) {
    bool no_product = true;
    stack< pair<string, float> > cheaper;
    cheaper.push(make_pair("init", 9999.00));
    for (auto iter_mkts = mkts_.begin(); iter_mkts != mkts_.end(); iter_mkts++) {
        for (auto iter_loca = mkts_[iter_mkts->first].begin(); iter_loca != mkts_[iter_mkts->first].end(); iter_loca++) {
            for (auto iter_pdt = iter_loca->second.begin(); iter_pdt != iter_loca->second.end(); iter_pdt++) {
                if (iter_pdt->name == pdt_name) {
                    no_product = false;
                    pair<string, float> tmp = cheaper.top();
                    if (iter_pdt->price <= tmp.second) {
                        cheaper.push(make_pair(iter_mkts->first + " " + iter_loca->first, iter_pdt->price));
                    }
                }
            }
        }
    }
    if (no_product) {
        cout << "This product is not available anywhere." << endl;
    } else {
        pair<string, float> tmp = cheaper.top();
        cheaper.pop();
        float price = tmp.second;
        cout << setiosflags(ios::fixed) << setprecision(2) << price << endl;
        vector<string> cheapest;
        cheapest.push_back(tmp.first);

        tmp = cheaper.top();
        while (tmp.second == price) {
            cheapest.push_back(tmp.first);
            cheaper.pop();
            tmp = cheaper.top();
        }
        sort(cheapest.begin(), cheapest.end(), smaller_name);
        for (int i = 0; i != cheapest.size(); i++) {
            cout << cheapest.at(i) << endl;
        }
    }
}

void Datastructure::selection(string chain_name, string location) {
    auto iter = mkts_[chain_name][location].begin();
    // map<string, float> tmp;
    if (iter == mkts_[chain_name][location].end()) {
        cout << "Error: Wrong chain name or location!" << endl;
    } else {
        sort(mkts_[chain_name][location].begin(), mkts_[chain_name][location].end(), smaller_product);
        while (iter != mkts_[chain_name][location].end()) {
            // tmp[iter->name] = iter->price;
            cout << iter->name << " " << setiosflags(ios::fixed) << setprecision(2) << iter->price << endl;
            iter++;
        }
        /*
        auto iter2 = tmp.begin();
        while (iter2 != tmp.end()) {
            cout << iter2->first << " " << setiosflags(ios::fixed) << setprecision(2) << iter2->second << endl;
            iter2++;
        }*/
    }
}
