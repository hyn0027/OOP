#include "graph.h"
#include "minus.h"
#include "plus.h"

Graph::Graph(int num_node) {
    // 预分配节点空间
    nodes_.initialize(num_node);
}

void Graph::InsertPlaceholder(const string &node_name) {
    // wait to fill, 使用nodes_.insert()新建一个占位符
    //
    Node* nd = new PlaceholderNode(node_name);
    nodes_.insert(node_name, nd);
    nd = nullptr;
}

void Graph::InsertConstant(const string &node_name, float value) {
    // wait to fill, 使用nodes_.insert()新建一个常量
    //
    Node* nd = new ConstantNode(node_name, value);
    nodes_.insert(node_name, nd);
    nd = nullptr;
}

void Graph::InsertOperation(const string &node_name, const string &operation_type, 
                                const string &input1, const string &input2) {
    // wait to fill, 根据operation_type的名字调用相应的运算符节点构造函数
    //
    if (operation_type == "-") {
        Node* nd = new Minus(node_name, nodes_[input1], nodes_[input2]);
        nodes_.insert(node_name, nd);
        nd = nullptr;
    }
    else {
        Node* nd = new Plus(node_name, nodes_[input1], nodes_[input2]);
        nodes_.insert(node_name, nd);
        nd = nullptr;
    }
}

void Graph::Eval(const string &node_name, const int &argument_num, 
                    const string* argument_name_list_, const float* argument_value_list_) {

    // wait to fill, 调用相应的placeholder的set_val函数
    for (int i = 0; i < argument_num; i++) {
        PlaceholderNode* a = dynamic_cast<PlaceholderNode*>(nodes_[argument_name_list_[i]]);
        a -> set_val(argument_value_list_[i]);
        //((PlaceholderNode*)nodes_[argument_name_list_[i]]) -> set_val(argument_value_list_[i]);
    }

    nodes_[node_name]->calc();
    float temp_value = nodes_[node_name]->value();
    cout << std::fixed << setprecision(2) << temp_value << endl;   
}

Graph::~Graph() {
    
}


/*
3 3 2
x P
y P
z C 3.0
a = x + y
b = a + x
a = x + z
EVAL a 2 x 2.0 y 1.0
EVAL b 2 x 2.0 y 1.0
*/
/*
是这样的 一些指针的问题
好几处是一样的qwq 包括Graph::InsertPlaceholder、Graph::InsertConstant、Graph::InsertOperation三个地方
窝就只详细说一个啦 说的是Graph::InsertOperation里operation_type==“+”的情况
一个是原来的i1 i2 b指向的位置在析构时会直接被删掉 然后再次调用的时候指向了啥都没有就崩了
另一个是a虽然不是指针类型，看起来不用管置空的问题 但是看一下mymap.cpp的insert函数会发现其实传来传去赋值的都是指向a的指针，a在析构的时候一旦被删掉哪传来传去的地址就都是虚无
所以解决办法是全改成指针然后全部置空
另外这么写其实有点麻烦qwq 因为全是左值 所以就要管一堆置空的麻烦事 窝把窝代码发给你叭~基本都是能强制类型转换就强制类型转换了，然后尽可能多的直接传指针/地址，比较少用左值
*/