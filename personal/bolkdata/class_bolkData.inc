<?php
/*
  This code is part of FusionDirectory (http://www.fusiondirectory.org/)
  Copyright (C) 2014-2019  FusionDirectory
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*/

class bolkData extends simplePlugin
{
  var $displayHeader = TRUE;

  // We need this function that returns some information about the plugin
  static function plInfo (): array
  {
    return [
      'plShortName'       => _('Bolk Data'),
      'plTitle'           => _('Bolk member info'),
      'plDescription'     => _('Manage bolk member information'),
      'plSelfModify'      => TRUE, // Does this plugin have an owner that might be able to edit its entry
      'plObjectType'      => ['user'],
      'plObjectClass'     => array('fdBolkData', 'fdBolkDataAVG'),
      'plFilter'          => '(&(objectClass=fdBolkData)(objectClass=fdBolkDataAVG))',
      'plIcon'            => 'geticon.php?context=applications&icon=user-info&size=48',
      'plSmallIcon'       => 'geticon.php?context=applications&icon=user-info&size=16',
      'plPriority'        => 3,

      // simplePlugin can generate the ACL list for us
      'plProvidedAcls'    => parent::generatePlProvidedAcls(self::getAttributesInfo())
    ];
  }


  static function getAttributesInfo (): array
  {
    return [
      'main' => [
        'name'  => _('Personal info'),
        'attrs' => [
          new StringAttribute(
            _('Nickname'), _('Nickname for this user'),
            'fdNickName', FALSE
          ),
          new DateAttribute(
            _('Date of birth'), _('Date of birth'),
            'dateOfBirth', FALSE,
            'Y-m-d', '',
            // min and max:
            NULL, 'now'
          ),
          new StringAttribute(
			_('Pronouns'), _('Pronouns this person uses'),
			'fdPronouns', FALSE
          ),
		  new SetAttribute(
			  new StringAttribute(
				_('Programme'), _('Programme(s) this member does'),
				'fdProgramme', FALSE
			  )
		  ),
		  new SetAttribute(
			  new StringAttribute(
				_('Institution'), _('The institution(s) the member attends'),
				'fdInstitution', FALSE
			  )
		  ),
		  new SetAttribute(
			  new PhoneNumberAttribute(
				_('Emergency contact number'), _('Phone number of the member\'s emergency contact'),
				'fdEmergencyPhone', FALSE )
		  )
		]
	  ],
	  'membership' => [
		  'name'   => _('Membership Info'),
		  'attrs'  => [
		  new DateAttribute(
            _('Date of inauguration'), _('Date of inauguration'),
            'fdDateOfInauguration', FALSE,
            'Y-m-d', '',
            NULL, 'now'
          ),
          new BooleanAttribute(
            _('IRA done'), _('Did this member complete the Instruction Responsible Alcohol'),
            'fdIVA', TRUE, FALSE
          ),
		  new DateAttribute(
            _('Date of resignation letter'), _('Date of resignation letter'),
            'fdDateOfResignationLetter', FALSE,
            'Y-m-d', '',
            NULL, 'now'
          ),
		  new DateAttribute(
            _('Date of resignation'), _('Date of resignation'),
            'fdDateOfResignation', FALSE,
            'Y-m-d', '',
            NULL, 'now'
          ),
		  new BooleanAttribute(
			_('Dead'), _('Has this member passed away?'),
			'fdDead', TRUE, FALSE
		  ),
          new BooleanAttribute(
            _('Photo Visible'), _('Should the photo of the user be visible on external tools?'),
            'fdPhotoVisible', FALSE, TRUE
          ),
          new BooleanAttribute(
            _('Door Access'), _('Is the user allowed to use their pass to open the door?'),
            'fdDoorAccess', FALSE, FALSE
          )
        ],
	  ],
	  'avg' => [
          'name'  => _('Personal info data preferences'),
          'attrs' => [
		  new BooleanAttribute(
			_('AVG accepted'), _('Did this member agree to the privacy statement'),
			'fdAVGAccept', TRUE, FALSE
		  ),
		  new BooleanAttribute(
			_('Share phone number'), _('Does this member allow to internally share their phone number'),
			'fdPhoneShare', TRUE, TRUE
		  ),
		  new BooleanAttribute(
			_('Share emergency phone number'), _('Does this member allow to internally share their emergency contact?'),
			'fdEmergencyPhoneShare', TRUE, FALSE
		  ),
		  new BooleanAttribute(
			_('Share mail address'), _('Does this member allow to internally share their mail address'),
			'fdMailShare', TRUE, TRUE
		  ),
		  new BooleanAttribute(
			_('Share home address'), _('Does this member allow to internally share their home address'),
			'fdAddressShare', TRUE, TRUE
		  ),
          new BooleanAttribute(
			_('Share pronouns'), _('Does this member allow to internally share their pronouns'),
			'fdPronounsShare', TRUE, TRUE
		  ),
		  new BooleanAttribute(
			_('Share date of birth'), _('Does this member allow to internally share their date of birth'),
			'fdDoBShare', TRUE, TRUE
		  ),
		  new BooleanAttribute(
			_('Share programme'), _('Does this member allow to internally share their programme'),
			'fdProgrammeShare', TRUE, TRUE
		  ),
		  new BooleanAttribute(
			_('Share institution'), _('Does this member allow to internally share where they study'),
			'fdInstitutionShare', TRUE, TRUE
		  )
        ],
      ],
    ];
  }
}
