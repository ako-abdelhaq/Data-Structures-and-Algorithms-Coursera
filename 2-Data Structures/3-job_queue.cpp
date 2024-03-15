#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::priority_queue;

using namespace std;

struct pair_comp{
    bool operator () (pair<int,long long> p1 , pair<int,long long> p2) {
        
        return (p1.second != p2.second && p1.second > p2.second)||(p1.second == p2.second && p1.first > p2.first) ;
        
    }
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;
  priority_queue< pair<int,long long> , vector<pair<int,long long>> , pair_comp > q;
  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0 ; i < num_workers_ ; i++){
        q.push(make_pair(i,0));
    }
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    long long finish_time = 0;
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      auto next_worker = q.top() ;
      q.pop();
      assigned_workers_[i] = next_worker.first;
      start_times_[i] = next_worker.second;
      finish_time = (long long)duration + next_worker.second;
      q.push( make_pair(next_worker.first , finish_time) );
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
