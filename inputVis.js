const numberData = [{x:3, y:4, number:0}, {x:6, y:6, number:1}, {x:8, y:5, number:2}, {x:3, y:2, number:3}, {x:7, y:5, number:4}, {x:5, y:2, number:5}, {x:10, y:3, number:6}, {x:6, y:5, number:7}, {x:7, y:1, number:8}, {x:5, y:0, number:9}, {x:9, y:3, number:10}, {x:8, y:3, number:11}, {x:8, y:4, number:12}, {x:4, y:1, number:13}, {x:1, y:3, number:14}, {x:4, y:4, number:15}, {x:9, y:5, number:16}, {x:0, y:3, number:17}, {x:4, y:3, number:18}, {x:3, y:3, number:19}, {x:5, y:7, number:20}, {x:6, y:0, number:21}, {x:6, y:7, number:22}, {x:9, y:4, number:23}, {x:5, y:3, number:24}, {x:5, y:6, number:25}, {x:2, y:4, number:26}, {x:4, y:2, number:27}, {x:4, y:6, number:28}, {x:5, y:4, number:29}];

const actionData = [[{x:6, y:1}, {x:6, y:2}, {x:6, y:3}, {x:6, y:4}, {x:6, y:5}, {x:6, y:6}, {x:6, y:7}, {x:7, y:1}, {x:7, y:2}, {x:7, y:3}, {x:7, y:4}, {x:7, y:5}, {x:7, y:6}, {x:7, y:7}], [{x:6, y:3}, {x:6, y:4}, {x:6, y:5}, {x:7, y:3}, {x:7, y:4}, {x:7, y:5}, {x:8, y:3}, {x:8, y:4}, {x:8, y:5}, {x:9, y:3}, {x:9, y:4}, {x:9, y:5}], [{x:5, y:0}, {x:5, y:1}, {x:5, y:2}, {x:5, y:3}, {x:5, y:4}, {x:5, y:5}, {x:6, y:0}, {x:6, y:1}, {x:6, y:2}, {x:6, y:3}, {x:6, y:4}, {x:6, y:5}], [{x:3, y:2}, {x:3, y:3}, {x:3, y:4}, {x:3, y:5}, {x:3, y:6}, {x:4, y:2}, {x:4, y:3}, {x:4, y:4}, {x:4, y:5}, {x:4, y:6}, {x:5, y:2}, {x:5, y:3}, {x:5, y:4}, {x:5, y:5}, {x:5, y:6}, {x:6, y:2}, {x:6, y:3}, {x:6, y:4}, {x:6, y:5}, {x:6, y:6}, {x:7, y:2}, {x:7, y:3}, {x:7, y:4}, {x:7, y:5}, {x:7, y:6}, {x:8, y:2}, {x:8, y:3}, {x:8, y:4}, {x:8, y:5}, {x:8, y:6}], [{x:4, y:1}, {x:4, y:2}, {x:4, y:3}, {x:4, y:4}, {x:5, y:1}, {x:5, y:2}, {x:5, y:3}, {x:5, y:4}, {x:6, y:1}, {x:6, y:2}, {x:6, y:3}, {x:6, y:4}, {x:7, y:1}, {x:7, y:2}, {x:7, y:3}, {x:7, y:4}, {x:8, y:1}, {x:8, y:2}, {x:8, y:3}, {x:8, y:4}]];

const numSizeData = 30;

const boardSizeX = 11;
const boardSizeY = 8;

const groupSizeData = 5;

const groupData = [[1, 4, 7, 8, 22], [2, 4, 7, 10, 11, 12, 16, 23], [5, 7, 9, 21, 24, 29], [0, 1, 2, 3, 4, 5, 7, 11, 12, 15, 18, 19, 24, 25, 27, 28, 29], [5, 8, 11, 12, 13, 15, 18, 24, 27, 29]];
