/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache = new Map();

    return function(...args) {
        let cur = cache;

        for (arg of args) {
            if (cur.has(arg)) {
                cur = cur.get(arg);
            } else {
                cur.set(arg, new Map());
                cur = cur.get(arg);
            }
        }

        if (cur.has('_value')) return cur.get('_value');

        const fnRes = fn(...args);
        cur.set('_value', fnRes);
        return fnRes;
    }
}