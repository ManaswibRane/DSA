/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let v=0;
    return function() {
             return n+v++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */