#CSCI 3060/SOFE 3980 -Assignment 1 (Project Phase 1)

###Due date

February 12th, 2016 <i>(extended)</i> at 11:00pm


###Marking scheme and Progress

Out of ten. Distributed the following way:

| CATEGORY | MARKS /10 | STATUS | COMMENTS
| -------- | --------- | ------ | --------
| List of Test Cases and What They are to Test | - | <font color='goldenrod'>In progress</font> | A table of test names an intentions, (in English)
|<ul><li><u>Descriptions</u>: Table of test cases telling which case each is intended to test. </li></ul> | 2 marks | - | Make sure to include all those included in the Slack #requirements channel.
|<ul><li><u>Completeness</u>: Test cases cover majority of cases allowed by requirements, and include cases to test all constraints</li></ul> | 2 marks | - | -
| Actual Test Case Inputs and Expected Outputs | - | <font color='goldenrod'>In progress</font> | For each case, the actual test input files and expected output files (as text file printouts). Need <i>at least</i> 80 test case files.
|<ul><li><u>Test Files</u>: All provided and with expected output</li></ul> | 2 marks | -
| Test Plan | - | <font color='red'>Pending</font> | How your tests are organized (e.g. directories), how they will be run (shell scripts/DOS batch files), and how the output will be stored and organized for reporting and comparison with later runs (make text file printouts of any directory structures and script files created
|<ul><li><u>Test input and output organization</u>: There is a good plan to keep test cases and results well organized</ul></li> | 2 marks | - | -
|<ul><li><u>Test Run Plan</u>: There is a workable plan for running all test cases</ul></li> | 1 mark | - | -
| Other | - | <font color='red'>Pending</font> | -
|<ul><li><u>Requirements Problems</u>: Problems found in the requirements are reported</ul></li> | 1 mark | - | Those already mentioned in the Slack #requirements channel will not be taken into account.

###Requirement Clarifications
(Slack **#requirements** channel)

New Feature:

- [ x ] enable - enable a bank account
	- should ask for the bank account holder's name (as a text line).
	- Should ask for the account number (as a text line).
	- Should change the bank account form disabled (D) to active (A).
	- Should save this information for the bank account transaction file.

	- Constraints
		- Privileged Transaction - Only accepted when logged in admin mode.
		- Account holder's name must be the name of an existing account holder.
		- Account number must be the number of the account holder specified.



- Assume accounts cannot complete more than 9,999 transactions per day.
- Check for EoF to see when the input file is complete.
- A second login attempt will be rejected and ignored. Subsequent transactions will be considered as part of the first account login.
- Front end is used to generate transaction output files that the back end will manage. Front end must also check for constraints and create output files that meet these constraints.
- Front end should check for transaction constraints. (Includes trying to withdraw more money than the account is allowed). If the front end is restarted and try again, it should still correctly fail to withdraw more money than allowed.
- Account balance can't go into negatives.
- Front end should should keep track of balances.
- Front end should not be reading in transaction output files, or start fresh each session from the master accounts list.
- Deposits should niether be available in the same login session or in the same day. You cannot access the funds until the next day after the back end has applied the transactions.
- An admin can delete an account that has been disabled.
- If the account name for account creation is greater than 20 characters, it should be truncated if necessary.
- The special bank account with account holder's name END_OF_FILE, the account number, active/disabled, and balance do not matter.
- The above rule for END_OF_FILE also applies to end of session line.
​- Everyone can add an extra flag to the end of the current and master bank accounts files, e.g. NNNNN_AAAAAAAAAAAAAAAAAAAA_S_PPPPPPPP_Q, where Q is S for student plans and N for non-student plans. (Copy pasta, you're on your own.)
- By default, accounts should be non-student plans.
- Changeplan should be able to change from student to non-student plans and vice-versa.
- Users should not be allowed to access the END_OF_FILE account.
- The front end needs to support input from command line input and text file. And it should wait unless your text file told it to terminate.
- Money will always be in the format of #####.## where # is a number 0-9. No dollar signs. Values that don't fit in this format aren't allowed.
- Admins can perform any action when they've logged into an account, unless the account is disabled. Reject log ins on non-matching name/accounts, even if they are an admin.
- Admins are allowed any amount that fit the #####.## format.
- Deduct the fee first with withdrawals, and then check if the remaining amount is enough. If it isn't, return the free.
- In paybill the company name will always be provided as 2 letters.
- Do not worry about the case where an account is deleted, no need to reserve the account number.
- When an account is disabled, the use can login, but no transactions can be made.
- Admins can re-enable an account. (Turn an account from disabled to active)
- At the end of each session, when the logout transaction is processed, a bank account transaction file for the session is written.
- When an account is disabled, no transactions should be allowed during the same session. The front end should keep track of each accounts have been disabled.
- Withdraw, Deposit, Transfer, and Paybill transactions are the ones that incur fees.
- Fees are not charged when an admin is logged in.
- Front end should keep track of if the current logged in user is standard or admin.
- Log when someone logs in. Use the transaction code "10" for login. For the Miscellaneous information , use "A" for admin and "S" for standard logins.
- Assume no two users can have the exact same name.
- Bank will only give out paper money, no coins. (i.e. $5, $10, $20, $50, $100)
- Assume bank is Canadian money only.
- Paper currency applies only to withdrawals.
- If you run enable on a disabled account, you can immediately run transactions with it again.
- If an account is changed to a student halfway through, the charges are at the student rate.
- "00" (end of session) is the transaction code for logging out.
- CC_AAAAAAAAAAAAAAAAAAAA_NNNNN_PPPPPPPP_QM is the format for each transaction in the bank account transaction file.
- NNNNN_AAAAAAAAAAAAAAAAAAAA_S_PPPPPPPP is the format for the current bank account.
- Maximum for withdrawal and transfer is for the entire day. These are limits on the account. Not the person.