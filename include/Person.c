/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "FirstASN"
 * 	found in "asn/first.asn"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#include "Person.h"

static asn_TYPE_member_t asn_MBR_Person_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Person, id),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"id"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Person, name),
		(ASN_TAG_CLASS_UNIVERSAL | (12 << 2)),
		0,
		&asn_DEF_UTF8String,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"name"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Person, age),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"age"
		},
};
static const ber_tlv_tag_t asn_DEF_Person_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Person_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 1 }, /* id */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 2, -1, 0 }, /* age */
    { (ASN_TAG_CLASS_UNIVERSAL | (12 << 2)), 1, 0, 0 } /* name */
};
static asn_SEQUENCE_specifics_t asn_SPC_Person_specs_1 = {
	sizeof(struct Person),
	offsetof(struct Person, _asn_ctx),
	asn_MAP_Person_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_Person = {
	"Person",
	"Person",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_Person_tags_1,
	sizeof(asn_DEF_Person_tags_1)
		/sizeof(asn_DEF_Person_tags_1[0]), /* 1 */
	asn_DEF_Person_tags_1,	/* Same as above */
	sizeof(asn_DEF_Person_tags_1)
		/sizeof(asn_DEF_Person_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_Person_1,
	3,	/* Elements count */
	&asn_SPC_Person_specs_1	/* Additional specs */
};

