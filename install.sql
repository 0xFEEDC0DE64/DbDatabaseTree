DROP TABLE IF EXISTS `Tree`;

CREATE TABLE `Tree` (
    `ID` INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `ParentID` INT UNSIGNED CHECK (`ID` <> `ParentID`),
    `Name` VARCHAR(255) NOT NULL,
    `Description` TEXT NOT NULL,
    UNIQUE(`ParentID`, `Name`),
    FOREIGN KEY (`ParentID`) REFERENCES `Tree`(`ID`)
);

INSERT INTO `test`.`tree` (`ParentID`, `Name`, `Description`) VALUES
(NULL, "root0", "Eine Testbeschreibung"),
(NULL, "root1", "Eine Testbeschreibung"),
(NULL, "root2", "Eine Testbeschreibung"),
(NULL, "root3", "Eine Testbeschreibung"),
(1, "root0sub0", "Eine Testbeschreibung"),
(1, "root0sub1", "Eine Testbeschreibung"),
(1, "root0sub2", "Eine Testbeschreibung"),
(1, "root0sub3", "Eine Testbeschreibung"),
(2, "root1sub0", "Eine Testbeschreibung"),
(2, "root1sub1", "Eine Testbeschreibung"),
(2, "root1sub2", "Eine Testbeschreibung"),
(2, "root1sub3", "Eine Testbeschreibung"),
(3, "root2sub0", "Eine Testbeschreibung"),
(3, "root2sub1", "Eine Testbeschreibung"),
(3, "root2sub2", "Eine Testbeschreibung"),
(3, "root2sub3", "Eine Testbeschreibung"),
(4, "root3sub0", "Eine Testbeschreibung"),
(4, "root3sub1", "Eine Testbeschreibung"),
(4, "root3sub2", "Eine Testbeschreibung"),
(4, "root3sub3", "Eine Testbeschreibung"),
(5, "root0sub0sub0", "Eine Testbeschreibung"),
(5, "root0sub0sub1", "Eine Testbeschreibung"),
(5, "root0sub0sub2", "Eine Testbeschreibung"),
(5, "root0sub0sub3", "Eine Testbeschreibung"),
(6, "root0sub1sub0", "Eine Testbeschreibung"),
(6, "root0sub1sub1", "Eine Testbeschreibung"),
(6, "root0sub1sub2", "Eine Testbeschreibung"),
(6, "root0sub1sub3", "Eine Testbeschreibung"),
(6, "root0sub2sub0", "Eine Testbeschreibung"),
(7, "root0sub2sub1", "Eine Testbeschreibung"),
(7, "root0sub2sub2", "Eine Testbeschreibung"),
(7, "root0sub2sub3", "Eine Testbeschreibung"),
(8, "root0sub3sub0", "Eine Testbeschreibung"),
(8, "root0sub3sub1", "Eine Testbeschreibung"),
(8, "root0sub3sub2", "Eine Testbeschreibung"),
(8, "root0sub3sub3", "Eine Testbeschreibung"),
(9, "root1sub0sub0", "Eine Testbeschreibung"),
(9, "root1sub0sub1", "Eine Testbeschreibung"),
(9, "root1sub0sub2", "Eine Testbeschreibung"),
(9, "root1sub0sub3", "Eine Testbeschreibung"),
(10, "root1sub1sub0", "Eine Testbeschreibung"),
(10, "root1sub1sub1", "Eine Testbeschreibung"),
(10, "root1sub1sub2", "Eine Testbeschreibung"),
(10, "root1sub1sub3", "Eine Testbeschreibung"),
(11, "root1sub2sub0", "Eine Testbeschreibung"),
(11, "root1sub2sub1", "Eine Testbeschreibung"),
(11, "root1sub2sub2", "Eine Testbeschreibung"),
(11, "root1sub2sub3", "Eine Testbeschreibung"),
(12, "root1sub3sub0", "Eine Testbeschreibung"),
(12, "root1sub3sub1", "Eine Testbeschreibung"),
(12, "root1sub3sub2", "Eine Testbeschreibung"),
(12, "root1sub3sub3", "Eine Testbeschreibung"),
(13, "root2sub0sub0", "Eine Testbeschreibung"),
(13, "root2sub0sub1", "Eine Testbeschreibung"),
(13, "root2sub0sub2", "Eine Testbeschreibung"),
(13, "root2sub0sub3", "Eine Testbeschreibung"),
(14, "root2sub1sub0", "Eine Testbeschreibung"),
(14, "root2sub1sub1", "Eine Testbeschreibung"),
(14, "root2sub1sub2", "Eine Testbeschreibung"),
(14, "root2sub1sub3", "Eine Testbeschreibung"),
(15, "root2sub2sub0", "Eine Testbeschreibung"),
(15, "root2sub2sub1", "Eine Testbeschreibung"),
(15, "root2sub2sub2", "Eine Testbeschreibung"),
(15, "root2sub2sub3", "Eine Testbeschreibung"),
(16, "root2sub3sub0", "Eine Testbeschreibung"),
(16, "root2sub3sub1", "Eine Testbeschreibung"),
(16, "root2sub3sub2", "Eine Testbeschreibung"),
(16, "root2sub3sub3", "Eine Testbeschreibung"),
(17, "root3sub0sub0", "Eine Testbeschreibung"),
(17, "root3sub0sub1", "Eine Testbeschreibung"),
(17, "root3sub0sub2", "Eine Testbeschreibung"),
(17, "root3sub0sub3", "Eine Testbeschreibung"),
(18, "root3sub1sub0", "Eine Testbeschreibung"),
(18, "root3sub1sub1", "Eine Testbeschreibung"),
(18, "root3sub1sub2", "Eine Testbeschreibung"),
(18, "root3sub1sub3", "Eine Testbeschreibung"),
(19, "root3sub2sub0", "Eine Testbeschreibung"),
(19, "root3sub2sub1", "Eine Testbeschreibung"),
(19, "root3sub2sub2", "Eine Testbeschreibung"),
(19, "root3sub2sub3", "Eine Testbeschreibung"),
(20, "root3sub3sub0", "Eine Testbeschreibung"),
(20, "root3sub3sub1", "Eine Testbeschreibung"),
(20, "root3sub3sub2", "Eine Testbeschreibung"),
(20, "root3sub3sub3", "Eine Testbeschreibung");
