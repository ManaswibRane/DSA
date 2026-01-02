function createCounter(n: number): () => number {
    let v=0;
    return function() {
        return n+v++;
    }
}


/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */