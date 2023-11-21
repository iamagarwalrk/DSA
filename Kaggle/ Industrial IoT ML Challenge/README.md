**Industrial IoT ML Challenge - Fall 2023**

Build a multi-class classifier for malicious network traffic

## Overview

Can machine learning identify when a network connection or intrusion is
malicious? Network security is a universal concern. And, as attack
mechanisms became more sophisticated, network security and
identification mechanisms had to adopt newer strategies as well. This
classroom challenge will introduce you to tackling network security
issues with machine learning.

Machine learning is used in a variety of security fronts. It's used to
detect malicious activity and stop attacks, analyze mobile endpoints,
enhance human analysis, automate repetitive security tasks, and close
zero-day vulnerabilities.

MIT's Lincoln Labs, as part of the 1998 Darpa Intrusion Detection
Evaluation Program, set up an environment to acquire nine weeks of raw
TCP data dumps for a local area network (LAN) simulating a typical U.S
Air Force LAN. They operated the LAN in a manner comparable to a true
Air Force environment except they peppered the LAN with numerous
attacks. This labeled data is what you'll be working with as you try to
tackle network security.

In this competition, you'll build algorithms to identify if a connection
is normal or part of a malicious attack. You'll be building a
multi-class classification model leveraging the network data provided by
Lincoln Labs. Winning models will be sure to carefully consider feature
engineering along with model selection to create flexible models able to
handle varied network traffic.

To be successful in this competition, you will need to build a machine
learning classifier capable of identifying the type of connection and
what type of traffic it is: normal or malicious. Along the way, you'll
gain familiarity with exploratory data analysis, data cleaning and
preparation, feature engineering, model selection, and hyper parameter
tuning.

## Dataset Description

## Files

-   **train.csv** - The training set, the labeled training data, the
    known ground truth. Use this to train your model(s).

-   **test.csv** - The test set, the unlabeled data. This is what you
    make predictions on. Extract the id column and use that to create
    your predictions, see sample_submission.csv. Do not remove
    duplicates from the test data. Each row in the test data requires a
    prediction.

-   **sample_submission.csv** - A sample submission file in the correct
    format

In the training set, the Category column will have each connection
labeled as either normal or an attack with exactly one type of attack
protocol specified. It was curated by MIT Lincoln Labs as part of the
1998 DARPA Intrusion Detection Evaluation Program. Lincoln Labs set up
an environment to acquire nine weeks of raw TCP data dumps for a local
area network (LAN) simulating a typical U.S Air Force LAN. They operated
the LAN in a manner comparable to a true Air Force environment except
they peppered the LAN with numerous attacks. Raw training data amounts
to four gigabytes of compressed TCP dump data across seven weeks of
network traffic. Approx five million connection records. Each connection
is \~ 100 bytes with 41 features.

In this competition, we are predicting if a given network connection is
malicious or not. In cases where a connection is malicious, we are to
identify the specific attack mechanism. Note that the test data includes
a slightly more diverse set of attack patterns than the train set.

Outside of a 'normal' connection, attacks can fall into one of 4 general
categories. These are general categories of attack types, **and are not
the labels you are to predict**, but to assist you in understanding the
major attack categories. There are 4 general categories:

-   **DOS** - Denial of service; ex. via custom crafted data or
    flooding. An attacker overwhelms a system\'s resources so that it\'s
    too busy to handle legitimate requests or denies access to a
    legitimate user

-   **R2L** - (Remote to User) Unauthorized access from a remote
    machine; ex. guessing a password

-   **U2R** - (User to Root) Unauthorized access to root privaleges; ex.
    buffer overflow attacks, Dictionary attacks / password sniffing etc.
    will be leveraged here to gain root access

-   **Probe** - Surveillance & scanning; ex. port scanning

  -----------------------------------------------------------------------
  **Specific attack type (label)**    **General attack category**
  ----------------------------------- -----------------------------------
  back                                dos

  buffer_overflow                     u2r

  ftp_write                           r2l

  guess_passwd                        r2l

  imap                                r2l

  ipsweep                             probe

  land                                dos

  loadmodule                          u2r

  multihop                            r2l

  neptune                             dos

  nmap                                probe

  perl                                u2r

  phf                                 r2l

  pod                                 dos

  portsweep                           probe

  rootkit                             u2r

  satan                               probe

  smurf                               dos

  spy                                 r2l

  teardrop                            dos

  warezclient                         r2l

  warezmaster                         r2l
  -----------------------------------------------------------------------

## Partial List of Column Descriptions

  -----------------------------------------------------------------------
  **Feature**             **Description**         **Type**
  ----------------------- ----------------------- -----------------------
  duration                length (number of       continuous
                          seconds) of the         
                          connection              

  protocol_type           type of the protocol,   discrete
                          e.g. tcp, udp, etc.     

  service                 network service on the  discrete
                          destination, e.g.,      
                          http, telnet, etc.      

  src_bytes               number of data bytes    continuous
                          from source to          
                          destination             

  dst_bytes               number of data bytes    continuous
                          from destination to     
                          source                  

  flag                    normal or error status  discrete
                          of the connection       

  land                    1 if connection is      discrete
                          from/to the same        
                          host/port; 0 otherwise  

  wrong_fragment          number of \`\`wrong\'\' continuous
                          fragments               

  urgent                  number of urgent        continuous
                          packets                 

  hot                     number of \`\`hot\'\'   continuous
                          indicators              

  num_failed_logins       number of failed login  continuous
                          attempts                

  logged_in               1 if successfully       discrete
                          logged in; 0 otherwise  

  num_compromised         number of               continuous
                          \`\`compromised\'\'     
                          conditions              

  root_shell              1 if root shell is      discrete
                          obtained; 0 otherwise   

  su_attempted            1 if \`\`su root\'\'    discrete
                          command attempted; 0    
                          otherwise               

  num_root                number of \`\`root\'\'  continuous
                          accesses                

  num_file_creations      number of file creation continuous
                          operations              

  num_shells              number of shell prompts continuous

  num_access_files        number of operations on continuous
                          access control files    

  num_outbound_cmds       number of outbound      continuous
                          commands in an ftp      
                          session                 

  is_hot_login            1 if the login belongs  discrete
                          to the \`\`hot\'\'      
                          list; 0 otherwise       

  is_guest_login          1 if the login is a     discrete
                          \`\`guest\'\'login; 0   
                          otherwise               
  -----------------------------------------------------------------------

## Feature data types:

duration: continuous.\
protocol_type: symbolic.\
service: symbolic.\
flag: symbolic.\
src_bytes: continuous.\
dst_bytes: continuous.\
land: symbolic.\
wrong_fragment: continuous.\
urgent: continuous.\
hot: continuous.\
num_failed_logins: continuous.\
logged_in: symbolic.\
num_compromised: continuous.\
root_shell: continuous.\
su_attempted: continuous.\
num_root: continuous.\
num_file_creations: continuous.\
num_shells: continuous.\
num_access_files: continuous.\
num_outbound_cmds: continuous.\
is_host_login: symbolic.\
is_guest_login: symbolic.\
count: continuous.\
srv_count: continuous.\
serror_rate: continuous.\
srv_serror_rate: continuous.\
rerror_rate: continuous.\
srv_rerror_rate: continuous.\
same_srv_rate: continuous.\
diff_srv_rate: continuous.\
srv_diff_host_rate: continuous.\
dst_host_count: continuous.\
dst_host_srv_count: continuous.\
dst_host_same_srv_rate: continuous.\
dst_host_diff_srv_rate: continuous.\
dst_host_same_src_port_rate: continuous.\
dst_host_srv_diff_host_rate: continuous.\
dst_host_serror_rate: continuous.\
dst_host_srv_serror_rate: continuous.\
dst_host_rerror_rate: continuous.\
dst_host_srv_rerror_rate: continuous.
