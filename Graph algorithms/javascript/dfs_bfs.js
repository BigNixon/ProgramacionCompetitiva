const dfs = (graph, source)=>{
    const stack = [source];

    while(stack.length > 0){
        const current = stack.pop();//takes the last node
        
        //process that node
        console.log(current);

        for (let neighbor of graph[current]){ //next node on the stack
            stack.push(neighbor);//add to the end
        }
    }
}

const bfs = (graph,source)=>{
    const queue = [source];
    while(queue.length>0){
        const current = queue.shift();//takes the first

        //process that node
        console.log(current);

        for (let neighbor of graph[current]){ //next node on the queue
            queue.push(neighbor);//add node to the end
        }
    }
}


const graph={
    a:  ['c','b'],
    b:  ['d'],
    c:  ['e'],
    d:  ['f'],
    e:  [],
    f:  []
};

dfs(graph,'a');
console.log("==========");
bfs(graph,'a');