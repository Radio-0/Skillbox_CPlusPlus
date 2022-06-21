/*Задача 2. Реализация класса графа
В любом доступном источнике прочитайте, что такое графы в дискретной математике и как граф можно представить в программе (что такое матрицы смежности и списки смежности)
Вам дан базовый интерфейс для представления ориентированного графа
Необходимо написать две реализаций интерфейса:
ListGraph, хранящий граф в виде массива списков смежности,
MatrixGraph, хранящий граф в виде матрицы смежности,
Также необходимо реализовать конструктор, принимающий IGraph*. Такой конструктор должен скопировать переданный граф в создаваемый объект (обратите внимание, что иногда в одну реализацию графа копируется другая) Реализуйте в том числе все конструкторы копий и операторы присваивания, если необходимо.
Чек-лист для проверки задачи
Реализованы два класса-наследника, имплементирующие корректные алгоритмы работы с графом как с матрицей смежности и списками смежности*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class IGraph {
public:
    virtual ~IGraph() {};

    IGraph() {};

    IGraph(IGraph* inOth) {};

    virtual void AddEdge(int from, int to) = 0;
    // Метод должен считать текущее количество вершин
    virtual int VerticesCount() const = 0;
    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetNextVertices(int vertex, vector<int>& vertices) const = 0;
    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const = 0;
};

class ListGraph : public IGraph {   //граф в виде массива списков смежности
    int numVertices = 0;
    map<int, int> arrayList;
public:
    ListGraph() {};

    ListGraph(IGraph* inOth) {
        numVertices = inOth->VerticesCount();
        for (int i = 1; i <= numVertices; i++) {
            vector<int> vertex;
            inOth->GetNextVertices(i, vertex);
            for (int n : vertex)
                this->AddEdge(i, n);
        }
    }

    virtual ~ListGraph() {
        map<int, int>::iterator it;
        for (it = arrayList.begin(); it != arrayList.end(); it++)
            cout << it->first << "-" << it->second << " ";
        cout << endl;
        cout << "Delete graph List\n";
    }
    ListGraph(const ListGraph& other) {
        arrayList = other.arrayList;
    }

    void AddEdge(int from, int to) { // Метод принимает вершины начала и конца ребра и добавляет ребро
        arrayList.insert(pair<int, int>(from, to));
    }

    void SizeArr(){
        map<int, int>::iterator it;
        int numb = 0;
        for (it = arrayList.begin(); it != arrayList.end(); it++){
            if(arrayList.find(it->first) != arrayList.end()) numVertices++;
        }
    }

    int VerticesCount() const { // Метод должен считать текущее количество вершин
        return numVertices;
    }

    void GetNextVertices(int vertex, vector<int>& vertices) const {  //можно дойти по ребру ИЗ данной
        vertices.clear();
        if(arrayList.find(vertex) != arrayList.end())
            vertices.push_back(arrayList.at(vertex));
        /*cout << "From " << vertex << " vertex to: ";
        for (int i = 0; i < vertices.size(); i++)
            cout << vertices[i] << " ";
        cout << endl;*/
    }

    void GetPrevVertices(int vertex, vector<int>& vertices) const {  // можно дойти по ребру В данную
        vertices.clear();
        for (auto it = arrayList.begin(); it != arrayList.end(); it++) {
            if (vertex == it->second)
                vertices.push_back(it->first);
        }
        /*cout << "To " << vertex << " vertex from: ";
        for (int i = 0; i < vertices.size(); i++)
            cout << vertices[i] << " ";
        cout << endl;*/
    }
};

class MatrixGraph : public IGraph { //граф в виде матрицы смежности
    int numVertices = 1;
    bool arr_matrix[100][100] = { 0,0 };
    int sizeArrI = 0, sizeArrJ = 0;
public:
    MatrixGraph() {};

    MatrixGraph(IGraph* inOth) {
        numVertices = inOth->VerticesCount();
        for (int i = 0; i <= numVertices; i++) {
            vector<int> vertex;
            inOth->GetNextVertices(i, vertex);
            for (int n : vertex)
                this->AddEdge(i, n);
        }
    }

    virtual ~MatrixGraph() {
        for (int i = 0; i < sizeArrI; i++) {
            for (int j = 0; j < sizeArrJ; j++)
                cout << arr_matrix[i][j] << " ";
            cout << endl;
        }
        cout << "Delete adjacency matrix\n";
    }

    MatrixGraph(const MatrixGraph& other) {
        for (int i = 0; i < sizeArrI; i++) {
            for (int j = 0; j < sizeArrJ; j++)
                arr_matrix[i][j] = other.arr_matrix[i][j];
        }
    }

    void AddEdge(int from, int to) { // Метод принимает вершины начала и конца ребра и добавляет ребро
        arr_matrix[from - 1][to - 1] = true;
        arr_matrix[to - 1][from - 1] = true;
        if (sizeArrJ < from)
            sizeArrJ = from;
        if (sizeArrI < to)
            sizeArrI = to;
        numVertices++;
    }

    int VerticesCount() const {   // Метод должен считать текущее количество вершин
        return numVertices;
    }

    void GetNextVertices(int vertex, vector<int>& vertices) const {    //можно дойти по ребру ИЗ данной
        vertices.clear();
        for (int i = 0; i < sizeArrJ; i++) {
            if (arr_matrix[vertex - 1][i] == true)
                vertices.push_back(i + 1);
        }
        /*cout << "From " << vertex << " vertex to: ";
        for (int i = 0; i < vertices.size() - 1; i++)
            cout << vertices[i] << " ";
        cout << endl;*/
    }

    void GetPrevVertices(int vertex, vector<int>& vertices) const { // можно дойти по ребру В данную
        vertices.clear();
        for (int i = 0; i < sizeArrI; i++) {
            if (arr_matrix[i][vertex - 1] == true)
                vertices.push_back(i + 1);
        }
        /*cout << "To " << vertex << " vertex from: ";
        for (int i = 0; i < vertices.size(); i++)
            cout << vertices[i] << " ";
        cout << endl;*/
    }
};

int main()
{
    vector<int> vertList;
    vector<int> vertMatrix;

    ListGraph listGraph;
    MatrixGraph matGraph;

    IGraph* list = new ListGraph();
    IGraph* matrix = new MatrixGraph();
    
    
    
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(2, 3);
    listGraph.AddEdge(3, 5);
    listGraph.AddEdge(5, 1);
    listGraph.AddEdge(4, 1);
    listGraph.AddEdge(3, 1);
    listGraph.SizeArr();
    cout << "Number vertices in array list: " << listGraph.VerticesCount() << endl;
    //listGraph.GetNextVertices(2, vertList);
    //listGraph.GetPrevVertices(2, vertList);
    
    matGraph.AddEdge(1, 2);
    matGraph.AddEdge(2, 3);
    matGraph.AddEdge(3, 4);
    matGraph.AddEdge(4, 5);
    cout << "Number vertices in adjacency matrix: " << matGraph.VerticesCount() << endl;
    //matGraph.GetNextVertices(3, vertMatrix);
    //matGraph.GetPrevVertices(1, vertMatrix);

    list->AddEdge(1, 2);
    list->AddEdge(2, 3);
    list->AddEdge(3, 4);
    list->AddEdge(4, 1);

    matrix->AddEdge(1, 2);
    matrix->AddEdge(1, 3);
    matrix->AddEdge(2, 3);

    ListGraph listGraph2(matrix);
    MatrixGraph matGraph2(list);

    return 0;
}