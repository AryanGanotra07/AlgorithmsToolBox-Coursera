# python3

import heapq

class Worker:
    def __init__(self, thread_id, release_time = 0):
        self.thread_id = thread_id
        self.release_time = release_time
    
    def __lt__(self, other):
        if self.release_time == other.release_time:
            return self.thread_id < other.thread_id
        return self.release_time < other.release_time
    
    def __gt__(self, other):
        if self.release_time == other.release_time:
            return self.thread_id > other.thread_id
        return self.release_time > other.release_time


class Jobs:
    def readData(self):
        self.numWorkers, m = map(int, input().split())
        self.jobs = list(map(int, input().split()))
        self.size = len(self.jobs)
        assert m==self.size

    def assign_jobs(self):
        self.result = []
        self.worker_queue = [Worker(i) for i in range(self.numWorkers)]

        for job in self.jobs:
            worker = heapq.heappop(self.worker_queue)
            self.result.append((worker.thread_id, worker.release_time))
            worker.release_time += job
            heapq.heappush(self.worker_queue, worker)
        
    def print_result(self):
        for wi, st in self.result:
            print(wi, st)


    def solve(self):
        self.readData()
        self.assign_jobs()
        self.print_result()



def main():
    jobs = Jobs()
    jobs.solve()


if __name__ == "__main__":
    main()
