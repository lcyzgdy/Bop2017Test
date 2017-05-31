var fs = require('fs');
fs.readFile('BoP2017-DBQA.train.txt', (err, data) => {
	var ques = data.toString().split('	');
	var quesResult = ques.forEach((name, index, ques) => {
		if (index % 3 == 1) {
			var fd = fs.openSync('Questions.txt', 'a', 0666);
			fs.writeSync(fd, name);
			fs.closeSync(fd);
		}
	});
	console.log('OK');
});