/*
MySQL Data Transfer
Source Host: localhost
Source Database: ss
Target Host: localhost
Target Database: ss
Date: 2020/7/27 17:44:38
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for device
-- ----------------------------
CREATE TABLE `device` (
  `dev_id` int(11) NOT NULL auto_increment,
  `serial` varchar(16) default NULL,
  `refresh` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  PRIMARY KEY  (`dev_id`),
  UNIQUE KEY `serial` (`serial`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for device_patient
-- ----------------------------
CREATE TABLE `device_patient` (
  `dev_id` int(11) NOT NULL,
  `patient_id` int(11) NOT NULL,
  `time` timestamp NOT NULL default CURRENT_TIMESTAMP,
  KEY `dev_id` (`dev_id`),
  KEY `patient_id` (`patient_id`),
  CONSTRAINT `dev_id` FOREIGN KEY (`dev_id`) REFERENCES `device` (`dev_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `patient_id` FOREIGN KEY (`patient_id`) REFERENCES `patient` (`patient_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for ecg
-- ----------------------------
CREATE TABLE `ecg` (
  `value` varbinary(1000) NOT NULL,
  `time` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  `dev_id` int(11) default NULL,
  KEY `device` (`dev_id`),
  CONSTRAINT `device` FOREIGN KEY (`dev_id`) REFERENCES `device` (`dev_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for patient
-- ----------------------------
CREATE TABLE `patient` (
  `patient_id` int(11) NOT NULL auto_increment,
  `name` char(5) NOT NULL,
  `sex` char(1) default NULL,
  PRIMARY KEY  (`patient_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `device` VALUES ('1', 'DEV_001', '2020-07-27 15:26:43');
INSERT INTO `device` VALUES ('2', 'DEV_002', '2020-07-27 15:26:00');
INSERT INTO `device` VALUES ('3', 'DEV_003', '2020-07-27 15:25:54');
INSERT INTO `device` VALUES ('4', 'DEV_004', '2020-07-27 15:25:45');
INSERT INTO `device` VALUES ('5', 'DEV_005', '2020-07-27 15:25:38');
INSERT INTO `device` VALUES ('6', 'DEV-002', '2020-07-27 17:36:48');
INSERT INTO `device_patient` VALUES ('5', '1', '2020-07-27 15:27:59');
INSERT INTO `device_patient` VALUES ('4', '2', '2020-07-27 15:28:06');
INSERT INTO `device_patient` VALUES ('3', '3', '2020-07-27 15:28:16');
INSERT INTO `device_patient` VALUES ('2', '4', '2020-07-27 15:28:24');
INSERT INTO `device_patient` VALUES ('1', '5', '2020-07-27 15:28:30');
INSERT INTO `ecg` VALUES ('��������', '2020-07-27 17:36:48', null);
INSERT INTO `patient` VALUES ('1', '沃滋植', '男');
INSERT INTO `patient` VALUES ('2', '侯智伟', '男');
INSERT INTO `patient` VALUES ('3', '董海月', '女');
INSERT INTO `patient` VALUES ('4', '李凯', '男');
INSERT INTO `patient` VALUES ('5', '赵首祯', '男');
