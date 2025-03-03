 #include <bits/stdc++.h>
 using namespace std;
 using namespace chrono;
 #define ll long long
 #define fi first
 #define sc second
 #define pll pair<ll,ll>
 #define pii pair<int,int>
 #define all(x) (x).begin(),(x).end()
 #define TASK "main"
const int nmax = 1e6 + 78;
int n;
double arr[nmax];
fstream inp;
fstream out;
double tot_time_qsort, tot_time_msort, tot_time_hsort, tot_time_csort; // tổng thời gian chạy của các thuật toán

// Code quicksort
namespace quicksort{ // quicksort
    double a[nmax];
    void quickSort(double a[], int l, int r){
        double p = a[(l+r)/2];
        int i = l, j = r;
        while (i < j){
            while (a[i] < p){
                i++;
            }
            while (a[j] > p){
                j--;
            }
            if (i <= j){
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }
        if (i < r){
            quickSort(a, i, r);
        }
        if (l < j){
            quickSort(a, l, j);
        }
    }
    void process(){
        for(int i = 1;i<=n;++i){
            a[i] = arr[i];
        }
        auto start = high_resolution_clock::now();
        quickSort(a, 1 , n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        tot_time_qsort += duration.count();
        out << "Quicksort : " << duration.count() << "ms"<< '\n'; // output result
    }
}
 // Code Heapsort
namespace Heapsort{
    void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(double arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
  void heapSort(double arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }
  double a[nmax];
  void process(){
        for(int i = 1;i<=n;++i) a[i] = arr[i];
        auto start = high_resolution_clock::now();
        heapSort(a, n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        tot_time_hsort += duration.count();
        out << "Heapsort : " << duration.count() << "ms"<< '\n'; // output result
  }
}
// code Mergesort
namespace Mergesort{
    double temp[nmax];
    void mergeParts(double arr[], int l, int mid, int r) {
        int i = l, j = mid + 1;
        int k = 0;

        while (i <= mid && j <= r) {
            double nextValue;

            if (arr[i] < arr[j]) nextValue = arr[i++];
            else nextValue = arr[j++];

            temp[k++] = nextValue;
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];

        for (int i=0; i<k; i++) arr[l + i] = temp[i];

    }

    void mergeSort(double arr[], int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        mergeParts(arr, l, mid, r);
    }
    double a[nmax];
    void process(){
        for(int i = 1;i<=n;++i) a[i] = arr[i];
        auto start = high_resolution_clock::now();
        mergeSort(a, 1, n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        tot_time_msort += duration.count();
        out << "Mergesort : " << duration.count() << "ms"<< '\n'; // output result
    }
}
// code sort của c++
namespace cppsort{
    double a[nmax];
    void process(){
        for(int i = 1;i<=n;++i) a[i] = arr[i];
        auto start = high_resolution_clock::now();
        sort(a+1, a+1+n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        tot_time_csort += duration.count();
        out << "Cppsort : " << duration.count() << "ms"<< '\n'; // output result
  }
}

 int main(){
     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fstream tmp;
    fstream clear;
    clear.open("result.out", std::fstream::out | std::fstream::trunc);
    clear.close();
    clear.open("cur_sum", fstream::out);
    clear << 0;
    clear.close();
     for(int ts = 1;ts <= 10;++ts){
        cerr << "Running test : #" << ts <<'\n';
        out.open("result.out", fstream::app);// output file
        out << "Test #" << to_string(ts) << '\n';
        inp.open(("test_" + to_string(ts) + ".inp").c_str(), fstream::in); // input file

        tmp.open("temp", fstream::out);
        tmp << ts;
        tmp.close();
        inp >> n;
        for(int i = 1;i<=n;++i) inp >> arr[i];
        inp.close();
        quicksort::process(); 
        Heapsort::process(); 
        Mergesort::process();
        cppsort::process();
        out.close();
        system("py main.py");
     }
     // tính toán thời gian chạy trung bình
     {
        out.open("result.out", fstream::app);
        out << "Average excecute time:" << '\n';
        out << "Quicksort : " << tot_time_qsort/10 << "ms" << '\n';
        out << "Heapsort : " << tot_time_hsort/10 << "ms" <<  '\n';
        out << "Mergesort : " << tot_time_msort/10 << "ms" << '\n';
        out << "C++sort : " << tot_time_csort/10 << "ms" << '\n';
        fstream pytime;
        pytime.open("cur_sum", fstream::in);
        double pyruntime;
        pytime >> pyruntime;
        out << "Pysort : " << pyruntime/10 << "ms" << '\n';
     }
 }  
 
 
 
