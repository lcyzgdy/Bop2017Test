var fs = require('fs');
fs.readFile('FinalAnswer.txt', (err, data) => {
	if (err) {
		console.log(err.message);
		return;
	}
	//console.log(data.toString());
	var ques = data.toString().split('	');
	//console.log(ques[2]);
	ques.forEach((value, index, ques) => {
		while (value.includes('\r')) {
			value = value.replace('\r', '');
		}
		while (value.includes('\n')) {
			value = value.replace('\n', '');
		}
		while (value.includes('##')) {
			value = value.replace('##', '\r\n');
		}
		var fd = fs.openSync('FinalAnswer.js.txt', 'a', 0666);
		fs.writeSync(fd, value);
		//fs.writeSync(fd, '\r\n');
		fs.closeSync(fd);
	});
	console.log('OK');
});