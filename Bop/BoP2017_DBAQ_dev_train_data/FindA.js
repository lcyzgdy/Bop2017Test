var fs = require('fs');
fs.readFile('ResultAnswer.dev.txt', (err, data) => {
	if (err) {
		console.log(err.message);
		return;
	}
	var ques = data.toString().split('	');
	ques.forEach((value, index, ques) => {
		var fd = fs.openSync('ResultAnswer.dev.js.txt', 'a', 0666);
		fs.writeSync(fd, value);
		fs.closeSync(fd);
	});
	console.log('OK');
});