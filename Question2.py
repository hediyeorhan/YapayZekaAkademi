def timeInWords(h, m):

	h_and_m = ["zero", "one", "two", "three", "four",
			"five", "six", "seven", "eight", "nine",
			"ten", "eleven", "twelve", "thirteen",
			"fourteen", "fifteen", "sixteen",
			"seventeen", "eighteen", "nineteen",
			"twenty", "twenty one", "twenty two",
			"twenty three", "twenty four",
			"twenty five", "twenty six", "twenty seven",
			"twenty eight", "twenty nine"];
    
	if (m == 0):
		print(h_and_m[h], "o' clock");

	elif (m == 1):
		print("one minute past", h_and_m[h]);

	elif (m == 59):
		print("one minute to", h_and_m[(h % 12) + 1]);

	elif (m == 15):
		print("quarter past", h_and_m[h]);

	elif (m == 30):
		print("half past", h_and_m[h]);

	elif (m == 45):
		print("quarter to", (h_and_m[(h % 12) + 1]));

	elif (m <= 30):
		print(h_and_m[m],"minutes past", h_and_m[h]);

	elif (m > 30):
		print(h_and_m[60 - m], "minutes to",
			h_and_m[(h % 12) + 1]);

	


if __name__ == '__main__':
    
	print("!! Enter a value between 1 and 24");
	h = int(input(" --> HOURS : "))
	while(h < 1 or h > 24):
		print("!! PLEASE -- Enter a value between 1 and 24")
		h = int(input(" --> HOURS : "))

	if(h>12):
		h=h-12;

	print("!! Enter a value between 0 and 59");
	m = int(input(" --> MINUTE : "))
	while(m < 0 or m > 59):
		print("!! PLEASE -- Enter a value between 0 and 59")
		m = int(input(" --> MINUTE : "))

	timeInWords(h, m);