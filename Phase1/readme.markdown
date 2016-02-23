#CSCI 3060/SOFE 3980 -Assignment 1 (Project Phase 1)

###Due date

February 14th, 2016 <i>(extended)</i> at 11:59pm

###Marking scheme and Progress

Out of ten. Distributed the following way:

| CATEGORY | MARKS /10 | STATUS | COMMENTS
| -------- | --------- | ------ | --------
| List of Test Cases and What They are to Test | - | <font color='green'>Complete</font> | A table of test names an intentions, (in English)
|<ul><li><u>Descriptions</u>: Table of test cases telling which case each is intended to test. </li></ul> | 2 marks | - | Make sure to include all those included in the Slack #requirements channel.
|<ul><li><u>Completeness</u>: Test cases cover majority of cases allowed by requirements, and include cases to test all constraints</li></ul> | 2 marks | - | -
| Actual Test Case Inputs and Expected Outputs | - | <font color='green'>Complete</font> | For each case, the actual test input files and expected output files (as text file printouts). Need <i>at least</i> 80 test case files.
|<ul><li><u>Test Files</u>: All provided and with expected output</li></ul> | 2 marks | -
| Test Plan | - | <font color='green'>Complete</font> | How your tests are organized (e.g. directories), how they will be run (shell scripts/DOS batch files), and how the output will be stored and organized for reporting and comparison with later runs (make text file printouts of any directory structures and script files created. <br>The test plan does not have to be a long report but a few paragraphs are probably necessary to explain the details.
|<ul><li><u>Test input and output organization</u>: There is a good plan to keep test cases and results well organized</ul></li> | 2 marks | - | -
|<ul><li><u>Test Run Plan</u>: There is a workable plan for running all test cases</ul></li> | 1 mark | - | -
| Other | - | <font color='green'>Complete</font> | -
|<ul><li><u>Requirements Problems</u>: Problems found in the requirements are reported</ul></li> | 1 mark | - | Those already mentioned in the Slack #requirements channel will not be taken into account.

###Files needed for the test case

![](http://i65.tinypic.com/2ymxgzm.png =550x)

###Requirement Clarifications
(Slack **#requirements** channel)

####By Command

######&rightarrow; Login

- [   ] Transfer code will be `10`. In the `MM`, `A` will be used for admin and `S` for standard user.

- [  **x** ] A second login attempt will be rejected and ignored. Subsequent transactions will be considered as part of the first account login.

- [ **x** ] Truncate account names if necessary

- [ **x** ] Users should not be able to access the END_OF_FILE account

- [   ] When an administrator logs in, all irrelevant field should either be filled with zeros or spaces - make sure it must be the correct number for either.

######&rightarrow;Withdrawal

- [ **x** ] Specified amount *must* be in the format #####.## or it will not be accepted. No dollar signs.

- [   ] Fees should be removed before the withdrawal is done

- [   ] Maximum withdrawn constraint is **for the entire day**.

######&rightarrow;Transfer

- **[   ] In the transaction file, *transfer* will be represented with two `02` lines, where the first implicitly represents the withdrawal and the second the deposit.**

- [ **x** ] Administrators have no monetary constraints, as long as the amount fits the format (#####.##)

- [ **x** ] Transfers must be **bigger** than $0.

- [ **x** ] Disabled users cannot receive transfers.

######&rightarrow;Paybill

- [ **x** ] Administrators have no monetary constraints, as long as the amount fits the format (#####.##)

- [ **x** ] Consider the different formats in which the company names may be inputted (e.g. "TV")

- [ **x** ] The 2000 constraint for standard users is per company, **per day**.

######&rightarrow;Deposit

- [ **x** ] Deposits should not be available for transactions neither in the same session **or in the same day**. Can only be accessed until the next day after the back end has applied the transactions.

- [ **x** ] Administrators have no monetary constraints, as long as the amount fits the format (#####.##)

######&rightarrow;Create

- [   ] Non-student is the default plan when creating an account.

- [ **xs** ] No underscores in names.

- [ **x** ] A created accound can't be used in the same **day**.

- [   ] A new account can be made with the old account number of a deleted account.

######&rightarrow;Delete

- [ **x** ] A disabled account **can** be deleted (by an administrator only).

- [   ] In the transaction line (*only one*) produced in the transaction file, there should be the account holder's name and number. The administrator does not have any identifiers.

######&rightarrow;Disable

- [   ] Once disabled, shouldn't wait until end of session for it to be effective should be immediate.

- [   ] In the transaction line (*only one*) produced in the transaction file, there should be the account holder's name and number. The administrator does not have any identifiers.

######&rightarrow;Change Plan

- [   ] Transaction fees change immediately after an account changes plans.

######&rightarrow;Logout

- [   ] Transaction code is `00`

######&rightarrow;Enable

- [   ] Should be able to run transactions again immediately after it has been enabled back.

####General

New Feature:

- [ **x** ] enable - enable a bank account (Transaction code `09`)
	- [ **x** ] should ask for the bank account holder's name (as a text line).
	- [ **x** ] Should ask for the account number (as a text line).
	- [ **x** ] Should change the bank account form disabled (D) to active (A).
	- [ **x** ] Should save this information for the bank account transaction file.

	- Constraints
		- [ **x** ] Privileged Transaction - Only accepted when logged in admin mode.
		- [ **x** ] Account holder's name must be the name of an existing account holder.
		- [ **x** ] Account number must be the number of the account holder specified.

- [   ] The front end should keep internal track of balances, but not read in transaction output files or start fresh each session from the master accounts list.

- [   ] The account number, active/disabled and balance do not matter for the END_OF_FILE account.

- **[   ] Add an extra flag to the end of the current and master bank account files: NNNNN_AAAAAAAAAAAAAAAAAAAA_S_PPPPPPPP_Q, where Q is S for student plans and N for non-student plans.**

- [   ] The front end should support input from both command line input and text files - at the same time, in the same session. Should always be waiting for command line inputs unless the text file tells it to terminate.

- [   ] Need some way to cause the front end to terminate (e.g. EOF or some other signal).

- [   ] One same used (same name) with multiple accounts should not be a problem.

- <font color='red'>[   ] Invalid input should take the user back to the place where they can try another transaction.</font>

- [   ] It is the responsibility of the **back end** to  manage the passing of days.

- [   ] In the transaction file, `MM` should be formatted like `A ` (space to the right). If it is not necessary for the file, leave as spaces.

- [   ] Assume accounts cannot complete more than 9,999 transactions per day.


####To Take Into Account
(Not necessarily requirements)

- [   ] Check for EoF to see when the input file is complete.
