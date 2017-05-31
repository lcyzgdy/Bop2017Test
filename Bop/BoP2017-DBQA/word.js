var fs = require('fs');
fs.readFile('BianChengZhiMei.DBQA.Part1.txt', (err, data) => {
	var str = data.toString();
	var item = str.split('[TITLE]:').toString().split('[QUESTION]:').toString().split('0	').toString().split('\r\n').toString();
	while (item.includes(',')) {
		item = item.replace(',', ' ');
	}
	fs.writeFile('result.txt', item, (err1) => {
		if (err1) {
			console.log(err1.message);
			return;
		}
		console.log('OK');
	});
});